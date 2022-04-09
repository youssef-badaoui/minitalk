/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:02:05 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/04/09 09:02:07 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid = 0;

void	reset(int *i, int *res)
{
	(*i) = 0;
	(*res) = 0;
}

void	restpls(int *i, int *res)
{
	char	del;

	del = 8;
	reset(&i, &res);
	write(1, &del, 1);
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int		i;
	static int		res;
	char			del;

	(void)p;
	if (g_pid != info->si_pid)
	{
		resetpls(&i, &res);
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

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sigo;

	(void)argv;
	if (argc != 1)
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
