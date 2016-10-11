# Unix File IO and standard IO 
1. examples of five functions: open, read, write, lseek, and close.
   /*If the file descriptor refers to a pipe, FIFO, or socket, lseek sets errno to ESPIPE and returns −1.*/ 
   /*The file’s offset can be greater than the file’s current size, in which case the next write to the file will extend the file. This is referred to as creating a hole in a file and is allowed.*/
2. examine the effect of various buffer sizes on the read and write functions.
3. examine the concept of atomic operation with regard to file I/O and the arguments to the open function.
4. examples of dup, fcntl, sync, fsync, and ioctl functions.
