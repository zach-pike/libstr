LIBNAME=libstr

OBJECTS = $(patsubst %.c,%.o, $(shell find lib/$(LIBNAME)/ -name *.c))
CC = gcc
CFLAGS = -I./lib/ -I./lib/$(LIBNAME) -fPIC -c
LDFLAGS =
OUT_FILE = $(LIBNAME).so

.PHONY: install
install: build
	cp $(OUT_FILE) /usr/local/lib/

	rsync -arvz --progress --include='*.h' --include="*/" --exclude="*" ./lib/$(LIBNAME)/ headers/
	cd /usr/local/include && mkdir $(LIBNAME)

	cp -r headers/* /usr/local/include/$(LIBNAME)/
	rm -r headers/

.PHONY: uninstall
uninstall:
	rm /usr/local/lib/$(OUT_FILE)
	rm -r /usr/local/include/$(LIBNAME)/

.PHONY: build
build: $(OBJECTS)
	$(CC) -shared -o $(OUT_FILE) $(OBJECTS)

.PHONY: all
all: $(OBJECTS)
	echo "$(OBJECTS)"

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(OBJECTS) $(OUT_FILE)