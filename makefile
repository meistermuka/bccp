CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/bccpHelpers.c src/bccpModule.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bccpapp
RM := rm -rf

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lgphoto2

.c.o:
	$(CC) -I/usr/local/include/gphoto2/gphoto2 -Isrc $(CFLAGS) $< -o $@

clean:
	-$(RM) $(OBJECTS) $(EXECUTABLE)
	-@echo ' '
