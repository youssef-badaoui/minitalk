/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:02:27 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/04/09 09:02:29 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		usleep(800);
	}
}

void	hand(int s)
{
	if (s == SIGUSR1)
		ft_putstr("done!\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s;

	i = 0;
	s.sa_handler = &hand;
	sigaction(SIGUSR1, &s, NULL);
	if (argc == 3 && ft_atoi(argv[1]))
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
		ft_putstr("arg error\n");
}
