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

## Redirection

Redirection changes process output from stdin/stdout to other file descriptor. Must remember it is not arguments, only in/out process.

Must check redirection in shell program below.

1. Redirection is preferred to Pipe. So redirection is worked after piping descriptor setted.