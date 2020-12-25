#ifndef MINISHELL_H
# define MINISHELL_H

#include "macro.h"
#include "lib.h"
#include "parser.h"
#include "env.h"

#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

char	**g_envp;
int		prompt(char *str);
int		redirection(char *exec);
int		piping(char *command);
void	sig_int();


int		cd(char *dir);
int		export(char *argv[]);
int		echo(int argc, char *argv[], char *envp[]);
int		env(int argc, char *argv[], char *envp[]);
int		pwd(int argc, char *argv[], char *envp[]);



#endif