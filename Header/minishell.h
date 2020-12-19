#ifndef MINISHELL_H
# define MINISHELL_H

#include "macro.h"
#include "lib.h"
#include "parser.h"

#include <sys/wait.h>

int redirection(char *exec, char *envp[]);
int piping(char *command, char *envp[]);

#endif