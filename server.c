#include "header.h"

void	handle_sig(int sig, siginfo_t *info, void* ucontext)
{
	static int c = 0;
	static unsigned char p = 0;

	(void) info;
	(void) ucontext;
	c++;
	if (sig == SIGUSR2)
		p = (p << 1) | 0b1;
	else if (sig == SIGUSR1)
		p = (p << 1) | 0b0;
	if (c == 8)
	{
		write(1, &p, 1);
		if (kill(info->si_pid, SIGUSR1) == -1)
			err("server ack error");
		c = 0;
		p = 0;
	}
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	(void) argv;
	if (argc != 1)
		err("invalid arguments");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handle_sig;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		err("signal handling error");
	else if (sigaction(SIGUSR2, &sig, NULL) == -1)
		err("signal handling error ");
	while (1)
		pause();
	return (0);
}