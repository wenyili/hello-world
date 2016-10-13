/*
 * My own dup2 function. int myowndup2(int oldfd, int newfd);
 * 1. Close targeted fd(newfd) if it is openned.
 * 2. Call dup() repeatedly until it returns newfd, meanwhile save all fds duplicated by it.
 * 3. Close all the other fds.
 *
 * BUG:it is not atomic. Multi-thread should be considered?
 */
#include "apue.h"
#include "unistd.h"

#define OPEN_MAX_GUESS 256

int myowndupfd(int oldfd, int newfd)
{
	int tmpfd, result;
	tmpfd = dup(oldfd);
	if (tmpfd == newfd || tmpfd == -1)
		return tmpfd;
	} else {
		result = myowndupfd(oldfd, newfd);
		close(tmpfd);
		return result;
	}
}	

int myowndup2(int oldfd, int newfd)
{
	int result;

	result = dup(oldfd);
	if (result < 0) {
		err_msg("oldfd isn't an open file descriptor");
		return -1;
	}
	if (close(result) < 0) {
		err_msg("close tmp fd error");
		return -1;
	}

	if (oldfd == newfd)
		return newfd;

	if (close(newfd) < 0) {	
		if (errno != EBADF)	//EBADF:newfd is not openned
			err_sys("close newfd error");
	}
	
	/*
	 *recursion instead of recycle
	 *so we don't have to save all open file descriptors for closing them latter.
	*/ 
	result = myowndupfd(oldfd, newfd);	
	if (result == -1 && (errno == EMFILE))
		errno = EBADF;

	return result;
}

