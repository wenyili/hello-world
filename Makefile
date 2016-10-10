#
# Makefile for printlimits
#
CC = gcc

FILES = printLimits.o errfunc.o
FILES_PATHMAX = pathmax.o errfunc.o
FILES_OPENMAX = openmax.o errfunc.o

all : printLimits pathmax openmax

printLimits : $(FILES)
	$(CC) $(FILES) -o $@ 
	@echo "make $@ finished on `date`"

pathmax : $(FILES_PATHMAX)
	$(CC) $(FILES_PATHMAX) -o $@ 
	@echo "make $@ finished on `date`"

openmax : $(FILES_OPENMAX)
	$(CC) $(FILES_OPENMAX) -o $@ 
	@echo "make $@ finished on `date`"

%.o : %.c %.h
	$(CC) -o $<

clean:
	rm -f *.o
	rm -f printLimits pathmax openmax
