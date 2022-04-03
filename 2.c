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


void handler(int s, siginfo_t *info, void *p)
{
    ft_putstr("message is resived\n");
    exit(1);
}

void send(char *s, int pid)
{
    int i;
    int m;

    i = 0;
    m = 7;
    while(s[i])
    {
        while(m >= 0)
        {
            if((s[i] >> i) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            m++;
        }
        i++;
    }    
}

int main(int argc, char **argv)
{
    pid_t   pid;
    struct sigaction sigo;

    if(argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    sigo.__sigaction_u.__sa_sigaction = &handler;
    sigaction(SIGUSR1, &sigo, NULL);
    sigaction(SIGUSR1, &sigo, NULL);
     while (1)
		pause();
}