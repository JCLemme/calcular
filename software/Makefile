CC=/opt/parallax/bin/propeller-elf-gcc
CFLAGS=-Wall -O3

OBJDIR=obj
BINDIR=bin

KERNNAME=kernel.bin
RUNTNAME=runtime.bin

KERNOBJ=$(OBJDIR)/kernel.o \
		$(OBJDIR)/spi.o \
		$(OBJDIR)/display.o 

RUNTOBJ=$(OBJDIR)/runtime.o

.PHONY: all kernel runtime clean cleanobj cleanbin cleandir

all: kernel runtime

kernel: $(OBJDIR) $(BINDIR) $(KERNOBJ) 
	$(CC) $(CFLAGS) -o $(BINDIR)/$(KERNNAME) $(KERNOBJ)
	
runtime: $(OBJDIR) $(BINDIR) $(RUNTOBJ)
	$(CC) $(CFLAGS) -o $(BINDIR)/$(RUNTNAME) $(RUNTOBJ)
	
clean: cleanobj cleanbin

cleanobj:
	rm -rf $(OBJDIR)/*
	
cleanbin:
	rm -rf $(BINDIR)/*

cleandir:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
	
# -----------------------------------------

$(OBJDIR): 
	mkdir $(OBJDIR)
	
$(BINDIR): 
	mkdir $(BINDIR)
	
$(OBJDIR)/kernel.o: kernel.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/kernel.o -c kernel.c
	
$(OBJDIR)/spi.o: spi.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/spi.o -c spi.c

$(OBJDIR)/display.o: display.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/display.o -c display.c

$(OBJDIR)/runtime.o: runtime.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/runtime.o -c runtime.c
