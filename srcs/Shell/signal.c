#include "minishell.h"

static void handle()
{
	//ft_double_free(g_envp);
}

void sig_int()
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);
}