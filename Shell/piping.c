#include "lib.h"

int piping()
{
	int fd[2];
	int pid;
	char buffer[30];
	char *argv[] = ft_split("echo -n \"test\"", ' ');

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		close(fd[1]);
		if(fd[0] != 0) {
			//duplicate pipe in to string, so alread read
			dup2(fd[0], 0);
			close(fd[0]);
		}
		execl("/bin/export", "export", "b=5", NULL);
	}
	else //parent = shell
	{
		close(fd[0]);
		if (fd[1] != 1) {
			//duplicate pipe out to stdout
			dup2(fd[1], 1);
			close(fd[1]);
		}
		execl("/bin/export", "export", "a=5", NULL);
	}
}