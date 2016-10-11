CC = gcc

FILES = lseektest.o errfunc.o
FILES_H = createAHole.o errfunc.o

all : a.out h.out

a.out : $(FILES)
	$(CC) $(FILES) -o $@
	@echo "make $@ finished on `date`"

h.out : $(FILES_H)
	$(CC) $(FILES_H) -o $@
	@echo "make $@ finished on `date`"

%.o : %.c %.h
	$(CC) -o $<

clean:
	rm -f *.o
	rm -f a.out h.out 
