#include "lib.h"

int main(int argc, char *argv[], char *envp[])
{
	if (ft_strcmp(argv[1], "-n"))
		ft_write(0, argv[2]);
	else
		ft_wrtie_n(0, argv[1]);
}