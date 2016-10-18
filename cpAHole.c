#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd, newfd, empty = 0;
	char buf = '\0';

	if((fd = open("file.hole", O_RDONLY)) < 0)
		err_sys("open error");
	if((newfd = open("file.hole.cp", O_CREAT | O_WRONLY, FILE_MODE)) < 0)
		err_sys("creat error");

	while (read(fd, &buf, 1) == 1) {
		if(buf == '\0') {
			empty++;
		} else {
			if (empty > 0) {
				if(lseek(newfd, empty, SEEK_CUR) < 0)
					err_sys("lseek error");
				empty = 0;
			}
			if (write(newfd, &buf, 1) != 1)
				err_sys("write error");
		}
	}

	close(fd);	
	close(newfd);	
}
