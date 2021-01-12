#ifndef MINISHELL_H
# define MINISHELL_H

#include "macro.h"
#include "lib.h"
#include "parser.h"
#include "env.h"

#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

int			g_last_ret;
char		**g_envp;
char		**g_input;
char		**g_cmd;
char		***g_pipe_cmd;
char		**g_argv;
char		**g_argv_p;

int			prompt(char *str);
char		**redirection(char **cmd, int fd[2]);
int			piping(char **command);
void		sig_int();


int			cd(char *dir);
int			export(char *argv[]);
int			echo(int argc, char *argv[], char *envp[]);
int			unset(char **argv);
int			env(int argc, char *argv[], char *envp[]);
int			pwd(int argc, char *argv[], char *envp[]);
int 		ft_exit();

int			is_cmd(char *cmd);

int			single(char **argv);
int 		multi(char **command);
void		std_backup(int fd[2], int backup[2]);
void		std_reset(int fd[2], int backup[2]);

char		***pipe_alloc(char **input);
void		child_exit();
int			work(char **cmd);

void		std_reset(int fd[2], int backup[2]);
void		std_reset(int fd[2], int backup[2]);
int			is_cmd(char *cmd);

#endif