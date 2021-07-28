#ifndef HEADER_H
#define HEADER_H
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str);
void	err(char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif