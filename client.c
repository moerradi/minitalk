#include "header.h"

void	send(char *str, pid_t pid)
{
	int sig;
	int i;
	int n;
	int bit;

	i = 0;
	while (str[i])
	{
		n = 7;
		while (n >= 0 && (usleep(150) || 1))
		{
			bit = ((str[i] >> n) & 0b1);
			if (bit)
				sig = kill(pid, SIGUSR2);
			else
				sig = kill(pid, SIGUSR1);
			if (sig == -1)
				err("invalid PID");
			n--;
		}
		i++;
	}
}

void	received(int signum)
{
	static int ack = 0;
	(void) signum;
	if (!ack)
	{
		ft_putstr("message received by the server");
		ack = 1;
	}
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		err("invalid arguments");
	signal(SIGUSR1, received);
	pid = ft_atoi(argv[1]);
	send(argv[2], pid);
	return (0);
}