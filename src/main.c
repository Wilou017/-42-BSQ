/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 13:04:03 by amaitre           #+#    #+#             */
/*   Updated: 2015/09/24 23:34:12 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_C
# define MAIN_C

# include "header.h"

#endif

int		map(void)
{
	write(2, "map error\n", 10);
	return (1);
}

int		ft_open_file(char *file, t_infos *infos)
{
	infos->fd = open(file, O_RDONLY);
	if (infos->fd == -1)
	{
		ft_putstr("can not open file\n", 2);
		return (1);
	}
	return (0);
}

int		ft_get_parameters(t_infos *infos)
{
	int		ret;
	int		j;
	char	buf[2];
	char	*height2;

	infos->i = 0;
	j = 0;
	infos->width = 0;
	height2 = malloc(sizeof(char*));
	while ((ret = read(infos->fd, buf, 1)))
	{
		if (infos->i == 0)
			height2[j++] = *buf;
		if (infos->i == 1 && *buf != '\n')
			infos->width++;
		else if (infos->i >= 2)
			break ;
		if (*buf == '\n')
			infos->i++;
	}
	infos->height = ft_atoi(height2, infos);
	if (infos->height == 0)
		return (map());
	free(height2);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		ret;
	char	buf[2];
	char	*buffer;
	t_infos	infos;

	i = 0;
	if (argc < 2)
	{
		buffer = malloc(sizeof(char*));
		while ((ret = read(0, &buf, 1)))
			buffer[i++] = *buf;
		ft_putstr(buffer, 1);
	}
	else if (argc >= 2)
	{
		while (*++argv)
		{
			j = 0;
			infos.width = 0;
			if (ft_open_file(*argv, &infos))
				break ;
			if (ft_get_parameters(&infos))
				return (0);
			i = 0;
			infos.tab = malloc(sizeof(*infos.tab) * infos.height);
			while (i < infos.height)
				infos.tab[i++] = malloc(sizeof(char) * infos.width);
			i = 0;
			j = 0;
			close(infos.fd);
			infos.fd = open(*argv, O_RDONLY);
			while ((ret = read(infos.fd, buf, 1)))
			{
				if ((*buf != infos.obstacle &&
					*buf != infos.point &&
					*buf != '\n' && j > 0) ||
					(*buf == '\n' && i != infos.width && j > 0))
					return (map());
				if (*buf == '\n')
				{
					j++;
					i = 0;
				}
				else if (j > 0)
					infos.tab[j - 1][i++] = *buf;
			}
			if (j != (infos.height + 1) || i != 0)
				return (map());
			ft_process(infos);
			i = 0;
			while (i < infos.height)
				free(infos.tab[i++]);
			free(infos.tab);
			i = 0;
			if (argc > 2)
				ft_putchar('\n');
		}
	}
	else
		ft_putstr("too many arguments\n", 2);
	return (1);
}
