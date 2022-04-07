#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>
#include <bits/sigaction.h>


pid_t g_pid = 0;

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

void	reset(int *i, int *res)
{
	(*i) = 0;
	(*res) = 0;
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int		i;
	static int		res;

	(void)p;
	if (g_pid != info->si_pid)
	{
		reset(&i, &res);
		g_pid = info->si_pid;
	}
	res *= 2;
	if (sig == SIGUSR1)
		res += 1;
	else if (sig == SIGUSR2)
		res += 0;
	if (++i == 8)
	{
		if (res == 0)
		  	kill(info->si_pid, SIGUSR1);
		 else
		{
			ft_putchar(res);
			reset(&i, &res);
		}
	}
}


int main(int argc, char **argv)
{
    pid_t pid;
    struct sigaction sigo;

    (void)argv;
	if(argc != 1)
		return (0);
    pid = getpid();
    ft_putstr("The PID is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
    sigo.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sigo, NULL);
    sigaction(SIGUSR2, &sigo, NULL);
    while (1)
			pause();
}