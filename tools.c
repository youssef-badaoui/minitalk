/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:02:34 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/04/09 09:02:36 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	ft_atoi(char *s)
{
	int	signe;
	int	res;
	int	i;

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
