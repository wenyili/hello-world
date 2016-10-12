CC = gcc

FILES = lseektest.o errfunc.o
FILES_H = createAHole.o errfunc.o
FILES_U = unbufferdio.o errfunc.o
FILES_F = fileflags.o errfunc.o

all : a.out h.out u.out f.out

a.out : $(FILES)
	$(CC) $(FILES) -o $@
	@echo "make $@ finished on `date`"

h.out : $(FILES_H)
	$(CC) $(FILES_H) -o $@
	@echo "make $@ finished on `date`"

u.out : $(FILES_U)
	$(CC) $(FILES_U) -o $@
	@echo "make $@ finished on `date`"

f.out : $(FILES_F)
	$(CC) $(FILES_F) -o $@
	@echo "make $@ finished on `date`"

%.o : %.c %.h
	$(CC) -o $<

clean:
	rm -f *.o
	rm -f a.out h.out u.out f.out
