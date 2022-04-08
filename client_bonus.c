#include "minitalk.h"

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
		usleep(700);
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
		ft_send(pid, 0);
	}
	else
		ft_putstr("argc error\n");
}