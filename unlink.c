#include "apue.h"
#include <fcntl.h>

/*
$ ls -l tempfile
-rw-r----- 1 sar
$ df /home
Filesystem 1K-blocks Used Available Use% Mounted on /dev/hda4 11021440 1956332 9065108 18% /home
$ done
df /home
the program is done, all open files are closed
now the disk space should be available
look at how big the file is
413265408 Jan 21 07:14 tempfile
check how much free space is available
$ ./a.out &
1364
$ file unlinked
ls -l tempfile
ls: tempfile: No such file or directory the directory entry is gone $ df /home see if the space is available yet
Filesystem 1K-blocks Used Available Use% Mounted on /dev/hda4 11021440 1956332 9065108 18% /home
run the program in Figure 4.16 in the background the shell prints its process ID
the file is unlinked
see if the filename is still there
Used  Available  Use%  Mounted on
Filesystem   1K-blocks
/dev/hda4     11021440  1552352    9469088   15%  /home
now the 394.1 MB of disk space are available
*/
int main(void)
{
	if (open("tempfile", O_RDWR) < 0)
		err_sys("open error");
	if (unlink("tempfile") < 0)
		err_sys("unlink error");
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");
	exit(0);
}
