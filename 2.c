#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}
int ft_atoi(char *s)
{
    int signe;
    int res;
    int i;

    res = 0;
    i = 0;
    signe = 1;
    if (s[0] == '-' || s[0] == '+')
    {
        if (s[i] == '-')
            signe = -1;
        i++;
    }
    while (s[i])
    {
        res = res * 10 + s[i] - 48;
        i++;
    }
    return (signe * res);
}

void	ft_send(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(800);
	}
}

void hand(int s)
{
	if (s == SIGUSR1)
	    ft_putstr("message recived\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s;

	i = 0;
	s.sa_handler = &hand;
	sigaction(SIGUSR1, &s, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_send(pid, argv[2][i]);
			i++;
		}
		//ft_send(pid, 0);
	}
	else
		ft_putstr("argc error\n");
}