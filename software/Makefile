CC=/opt/parallax/bin/propeller-elf-gcc
CFLAGS=-Wall

OBJDIR=obj
BINDIR=bin

KERNNAME=kernel.bin
RUNTNAME=runtime.bin

KERNOBJ=$(OBJDIR)/kernel.o
RUNTOBJ=$(OBJDIR)/runtime.o

.PHONY: all kernel runtime clean cleanobj cleanbin cleandir

all: kernel runtime

kernel: $(OBJDIR) $(BINDIR) $(KERNOBJ) 
	$(CC) $(CFLAGS) -o $(KERNNAME) $(KERNOBJ)
	
runtime: $(OBJDIR) $(BINDIR) $(RUNTOBJ)
	$(CC) $(CFLAGS) -o $(RUNTNAME) $(RUNTOBJ)
	
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
	
$(OBJDIR)/kernel.o:
	$(CC) $(CFLAGS) -o $(OBJDIR)/kernel.o -c kernel.c
	
$(OBJDIR)/runtime.o:
	$(CC) $(CFLAGS) -o $(OBJDIR)/runtime.o -c runtime.c
