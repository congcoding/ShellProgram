#include "minishell.h"

static void handle()
{
	ft_double_free(g_envp);
	exit(1);
}

void sig_int()
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);
}