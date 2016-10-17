/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:27:02 by jtranchi          #+#    #+#             */
/*   Updated: 2015/09/24 16:36:23 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_C
# define FUNCTIONS_C

# include "header.h"

#endif

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int output)
{
	while (*str)
		write(output, str++, 1);
}

int		ft_atoi(const char *str, t_infos *infos)
{
	int		value;
	int		i;

	value = 0;
	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		value = value + (str[i] - '0');
		value *= 10;
		i++;
	}
	infos->point = str[i];
	infos->obstacle = str[i + 1];
	infos->croix = str[i + 2];
	return (value / 10);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_printtab(t_infos infos)
{
	int i;
	int j;

	i = 0;
	while (i < infos.height)
	{
		j = 0;
		while (j < infos.width)
		{
			ft_putchar(infos.tab[i][j++]);
		}
		ft_putchar('\n');
		i++;
	}
}
