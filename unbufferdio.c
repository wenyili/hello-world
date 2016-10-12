#include "apue.h"
#include <fcntl.h>

#define BUFFSIZE 10 

int main(void)
{
	int n;
//	int fd;
	char buf[BUFFSIZE];

/*	fd = open("test.txt", FILE_MODE);	
	while ((n = read(fd, buf, BUFFSIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	}
*/
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if (write(STDOUT_FILENO, "#", 1) != 1)
			err_sys("write error");
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	}
	
	if (n < 0)
		err_sys("read error");
	exit(0);
}
