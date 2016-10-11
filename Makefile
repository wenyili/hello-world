CC = gcc

FILES_U = unbufferdio.o errfunc.o
FILES_B = bufferdio.o errfunc.o

all : u.out b.out

u.out : $(FILES_U)
	$(CC) $(FILES_U) -o $@
	@echo "make $@ finished on `date`"

b.out : $(FILES_B)
	$(CC) $(FILES_B) -o $@
	@echo "make $@ finished on `date`"

%.o : %.c %.h
	$(CC) -o $<

clean:
	rm -f *.o
	rm -f u.out b.out 
