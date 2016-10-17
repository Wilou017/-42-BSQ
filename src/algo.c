/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 19:57:39 by jtranchi          #+#    #+#             */
/*   Updated: 2015/09/24 16:07:53 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_C
# define ALGO_C

# include "header.h"

#endif

int		ft_check(int y, int *x, int test, t_infos infos)
{
	int ytest;
	int xtest;
	int ix;

	ix = *x;
	ytest = y + test;
	xtest = ix + test;
	if (ytest >= infos.height || xtest >= infos.width)
		return (0);
	while (y < ytest)
		if (infos.tab[y++][xtest] == infos.obstacle)
			return (0);
	while (ix <= xtest)
	{
		if (infos.tab[ytest][ix++] == infos.obstacle)
		{
			if (xtest < infos.width - 1)
				*x = xtest + 1;
			return (0);
		}
	}
	return (1);
}

void	ft_putsquare(t_infos infos)
{
	int ytemp;
	int xtemp;

	ytemp = infos.ypos + infos.size;
	xtemp = infos.xpos + infos.size;
	while (infos.ypos <= ytemp)
	{
		while (infos.xpos <= xtemp)
		{
			infos.tab[infos.ypos][infos.xpos] = infos.croix;
			infos.xpos++;
		}
		infos.xpos = infos.xpos - (infos.size + 1);
		infos.ypos++;
	}
	ft_printtab(infos);
}

void	ft_process_2(t_infos *infos, int x, int y)
{
	int test;

	test = 1;
	if (infos->tab[y][x] != infos->obstacle)
	{
		while (ft_check(y, &x, test, *infos))
		{
			if (test > infos->size)
			{
				infos->size = test;
				infos->xpos = x;
				infos->ypos = y;
			}
			test++;
		}
	}
}

void	ft_process(t_infos infos)
{
	int x;
	int y;

	x = 0;
	y = 0;
	infos.xpos = 0;
	infos.ypos = 0;
	infos.size = 0;
	while (y < infos.height - infos.size)
	{
		while (x < infos.width - infos.size)
		{
			ft_process_2(&infos, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	ft_putsquare(infos);
}
