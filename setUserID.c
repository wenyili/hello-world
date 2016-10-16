#include "apue.h"
#include <fcntl.h>

/*
$ ls -l a.out
-rwxrwxr-x 1 sar
$ ./a.out a.out
read access OK
open for reading OK
$ ls -l /etc/shadow
-r-------- 1 root
$ ./a.out /etc/shadow
access error for /etc/shadow: Permission denied open error for /etc/shadow: Permission denied
$ su
Password:
# chown root a.out
# chmod u+s a.out
# ls -l a.out
-rwsrwxr-x 1 root
# exit
$ ./a.out /etc/shadow
access error for /etc/shadow: Permission denied open for reading OK
*/
int main(int argc, char **argv)
{
	if (argc != 2)
		err_quit("usage:%s [pathname]", argv[0]);

	if (access(argv[1], R_OK) < 0)
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");

	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");

	exit(0);
}
