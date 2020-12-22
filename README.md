# MiniShell Project

> OBJECT

1. Acknownledge of process.
2. Acknownledge of process piping

## Func

1. **echo**
	- Printing string in terminal
	- with `-n`

2. **export**
	- It is not linux program, only work in shell.
	- Export variable only work own process or child process, so cant connect & set variables in parent.

## Pipe

Process has own dependency memories, so cant connect memory through processes. Pipe make connection with two process, possible communicating each processes.

```c
#include <unistd.h>
int pipe(int fd[2]);
```

Pipe gets file descriptors(`fd[2]`). `fd[0]` is **exit of pipe**, `fd[1]` is **entrance of pipe**

Must check pipe in shell program below.

1. Child process get only stdout in parent process, so redirection is not duplicated
2. pipe is one side communitate default, so one side should close.

### Multi piping line

```cpp
int piping(char *cmds, char *envp[])
{
	int fd[2];
	int fd_in = 0;
	int pid;

	while (*cmds)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(cmds + 1))
				dup2(fd[1], 1);
			close(fd[0]);
			execve(*cmds, NULL, envp);
			exit(0);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			//input piping sequencly
			fd_in = fd[0];
			cmds++;
		}
	}
}
```

## Redirection

Redirection changes process output from stdin/stdout to other file descriptor. Must remember it is not arguments, only in/out process.

Must check redirection in shell program below.

1. Redirection is preferred to Pipe. So redirection is worked after piping descriptor setted.

## Quotes

Quote doesn't use for distinguishing string or number. `'123'`, `"123"`, `123` are same string. Quote is used for below.

1. Make one argv with space char.
2. Use enter in argv.
3. Emphasize string.

### Special Charactor 

- `$` : Get variable.
- ``` : backtick
- `!` : history operand

We use `\`, escape this contents;

### No quote

When no quote, all charactor are escaped like below.
```sh
$ echo \a\b\c\d
$ adcd

$ echo \\ta ## \is work \t => tab
$	a
```

### Double quotes(") / Single quotes(')

Special character is interpreted in Double quotes, but single is not, ever no escapce.