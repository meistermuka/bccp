CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/bccpHelpers.c src/bccpModule.c
INCLUDES=-I/usr/local/include/gphoto2/gphoto2 -Isrc
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bccpapp
RM := rm -rf

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/$@ -lgphoto2

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	-$(RM) $(OBJECTS) bin/$(EXECUTABLE)
	-@echo ' '
