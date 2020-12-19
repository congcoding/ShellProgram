#include "minishell.h"

int main(int argc, char *arg[], char *envp[])
{
	int in_fd = open("./in.txt", O_RDONLY);
	int out_fd = open("./out.txt", O_WRONLY);

	dup2(in_fd, 0);
	dup2(out_fd ,1);

	execl("/bin/grep", "grep", "1", NULL);
}