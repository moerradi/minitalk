#include "header.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	err(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_putnbr(int n)
{
	unsigned int	last;
	unsigned int	temp;

	temp = n;
	if (n < 0)
	{
		ft_putchar('-');
		temp = -n;
	}
	if (temp >= 10)
	{
		last = temp % 10;
		ft_putnbr(temp / 10);
		ft_putchar(last + 48);
	}
	else
		ft_putchar(temp + 48);
}

int	ft_atoi(const char *str)
{
	long	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
			result = result * 10 + *str++ - '0';
	}
	if (*str != '\0')
		return (-1);
	return (result);
}