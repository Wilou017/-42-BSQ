/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:50:56 by jtranchi          #+#    #+#             */
/*   Updated: 2015/09/24 16:09:20 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct	s_infos
{
	int			height;
	int			width;
	int			xpos;
	int			ypos;
	int			size;
	int			fd;
	int			i;
	char		point;
	char		croix;
	char		obstacle;
	char		**tab;
}				t_infos;

void			ft_putstr(char *str, int output);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
int             ft_atoi(const char *str, t_infos *infos);
int				ft_check(int y, int *x, int test, t_infos infos);
void			ft_process(t_infos infos);
void			ft_printtab(t_infos infos);
void			ft_putsquare(t_infos infos);

#endif
