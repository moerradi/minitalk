#include "header.h"

static void	send(char *str, pid_t pid)
{
	int sig;
	int i;
	int n;
	int bit;

	i = 0;
	while (str[i])
	{
		n = 7;
		while (n >= 0)
		{
			bit = ((str[i] >> n) & 0b1);
			if (bit)
				sig = kill(pid, SIGUSR2);
			else
				sig = kill(pid, SIGUSR1);
			if (sig == -1)
				err("invalid PID");
			n--;
			pause();
			// usleep(70);
		}
		i++;
	}
}

static void	received(int signum)
{
	(void) signum;
	usleep(70);
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		err("invalid arguments");
	signal(SIGUSR1, received);
	pid = ft_atoi(argv[1]);
	if (pid == -1 || pid == 0)
		err("PID should be a no null positive number");
	send(argv[2], pid);
	ft_putstr("message received by server !");
	return (0);
}
