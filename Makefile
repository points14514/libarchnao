CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC
LDFLAGS = -shared
PREFIX = /usr/local

# 库名称
LIB_NAME = libpoiapi-undermath
VERSION = 1.0.0

# 源文件
SRCS = src/undermath.c src/poisxapi.c
OBJS = $(SRCS:.c=.o)

# 目标文件
TARGET = $(LIB_NAME).so.$(VERSION)
SONAME = $(LIB_NAME).so.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -Wl,-soname,$(SONAME) -o $@ $^ -lm
	ln -sf $(TARGET) $(SONAME)
	ln -sf $(SONAME) $(LIB_NAME).so

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

install: $(TARGET)
	install -d $(PREFIX)/lib
	install -d $(PREFIX)/include
	install -m 755 $(TARGET) $(PREFIX)/lib/
	install -m 644 include/undermath.h $(PREFIX)/include/
	install -m 644 include/poisxapi.h $(PREFIX)/include/
	ldconfig
	@echo "Installation complete!"

uninstall:
	rm -f $(PREFIX)/lib/$(LIB_NAME).so*
	rm -f $(PREFIX)/include/undermath.h
	rm -f $(PREFIX)/include/poisxapi.h
	ldconfig
	@echo "Uninstallation complete!"

clean:
	rm -f src/*.o $(LIB_NAME).so*

.PHONY: all install uninstall clean
