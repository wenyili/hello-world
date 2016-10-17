CC = gcc

FILES = lseektest.o errfunc.o
FILES_H = createAHole.o errfunc.o
FILES_U = unbufferdio.o errfunc.o
FILES_F = fileflags.o errfunc.o
FILES_D = myowndup2.o errfunc.o
FILES_I = filetype.o errfunc.o
FILES_S = setUserID.o errfunc.o
FILES_M = umask.o errfunc.o
FILES_B = unlink.o errfunc.o
FILES_C = changeTime.o errfunc.o
FILES_W = fileWalker.o errfunc.o util.c

all : a.out h.out u.out f.out d.out i.out s.out m.out b.out c.out w.out

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

d.out : $(FILES_D)
	$(CC) $(FILES_D) -o $@
	@echo "make $@ finished on `date`"

i.out : $(FILES_F)
	$(CC) $(FILES_F) -o $@
	@echo "make $@ finished on `date`"

s.out : $(FILES_S)
	$(CC) $(FILES_S) -o $@
	@echo "make $@ finished on `date`"

m.out : $(FILES_M)
	$(CC) $(FILES_M) -o $@
	@echo "make $@ finished on `date`"

b.out : $(FILES_B)
	$(CC) $(FILES_B) -o $@
	@echo "make $@ finished on `date`"

c.out : $(FILES_C)
	$(CC) $(FILES_C) -o $@
	@echo "make $@ finished on `date`"

w.out : $(FILES_W)
	$(CC) $(FILES_W) -o $@
	@echo "make $@ finished on `date`"

%.o : %.c %.h
	$(CC) -o $<

clean:
	rm -f *.o
	rm -f a.out h.out u.out f.out d.out i.out s.out m.out b.out c.out w.out
