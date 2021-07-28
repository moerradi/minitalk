#include "header.h"

int main(int argc, char **argv)
{
	int	pid;
	int	bit;
	int	n;
	int	i;
	if (argc != 3)
		err("invalid arguments");
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		n = 7;
		while (n >= 0)
		{
			bit = ((argv[2][i] >> n) & 0b1);
			if (bit)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			n--;
			usleep(300);
		}
		i++;
	}
}