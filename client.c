/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:02:16 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/04/09 09:02:19 by ybadaoui         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int					pid;
	int					i;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3 && pid >= 0)
	{
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
