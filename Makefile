#
# Makefile for printlimits
#
CC = gcc

FILES = printLimits.o errfunc.o

#CFLAGS +=

all : printLimits

printLimits : $(FILES)
	$(CC) $(FILES) -o $@ 
	@echo "make $@ finished on `date`"

%.o : %.c %.h
	$(CC) -o $<

clean:
	rm -f *.o
	rm -f printLimits
