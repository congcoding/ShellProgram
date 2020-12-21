#include "pwd.h"

int main(int argc, char *argv[], char *envp[])
{
	char *pwd;
	
	if (!(pwd = get_env(envp, "PWD")))
		exit(1); //errno 처리
	ft_write_n(1, pwd);
}