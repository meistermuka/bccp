OBJS += \
./src/bccpHelpers.o \
./src/bccpModule.o 

CFLAGS=-c -Wall

RM := rm -rf

all: bccpModule

bccpModule: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -o bccpapp $(OBJS) -I/user/local/include/gphoto2/gphoto2 -I"/home/muka/REPOS/GIT/bccp/src" -O0 -g3 -Wall -c -fmessage-length=0
	@echo 'Finished building: $<'
	@echo ' '

bccpHelpers.o: bccpHelpers.c
	gcc $(CFLAGS) bccpHelpers.c

bccpModule.o: bccpModule.c
	gcc $(CFLAGS) bccpModule.c

clean:
	-$(RM) $(OBJS) bccpapp
	-@echo ' '