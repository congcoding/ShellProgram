#include "minishell.h"

static void handle()
{
	ft_write_n(1, "");
	ft_write(1, "$> ");
}

void sig_int()
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);
}