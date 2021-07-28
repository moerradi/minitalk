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
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (result > 9223372036854775807 / 10
			|| ((result == 9223372036854775807 / 10) && (*str - '0' > 7)))
			return ((sign > 0) * -1);
		else
			result = result * 10 + *str++ - '0';
	}
	return (sign * result);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}