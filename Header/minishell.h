/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:13:38 by seolim            #+#    #+#             */
/*   Updated: 2021/01/14 17:33:20 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "macro.h"
# include "lib.h"
# include "parser.h"
# include "env.h"
# include "get_next_line.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <signal.h>

int			g_last_ret;
char		**g_envp;
char		**g_input;
char		**g_cmd;
char		***g_pipe_cmd;
char		**g_argv;
char		**g_argv_p;
int			g_pid;

int			prompt(char **line);
char		**redirection(char **cmd, int fd[2]);
int			piping(char **command);
void		sig_int();

int			cd(char *dir);
int			export(char *argv[]);
int			echo(int argc, char *argv[], char *envp[]);
int			unset(char **argv);
int			env(int argc, char *argv[], char *envp[]);
int			pwd(int argc, char *argv[], char *envp[]);
int			ft_exit(void);

int			is_cmd(char *cmd);

int			single(char **argv);
int			multi(char **command);
void		std_backup(int fd[2], int backup[2]);
void		std_reset(int fd[2], int backup[2]);

char		***pipe_alloc(char **input);
void		child_exit();
int			work(char **cmd);
void		pipe_cmd_free(void);

void		std_reset(int fd[2], int backup[2]);
void		std_reset(int fd[2], int backup[2]);
int			is_cmd(char *cmd);

void		error_p(char *input);

#endif
