#ifndef MINISHELL_H
# define MINISHELL_H

#include "macro.h"
#include "lib.h"
#include "parser.h"
#include "env.h"

#include <sys/wait.h>
#include <errno.h>
#include <string.h>

char	**g_envp;
int		redirection(char *exec);
int		piping(char *command);

int		cd(char *dir);

#endif