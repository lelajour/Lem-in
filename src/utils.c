/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:34:51 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/04 05:44:01 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/lemin.h"

int		ft_start_chr(int **link, int nb, t_path *path)
{
	int	j;
	int	i;

	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (link[i][j] == 1 && path->start == -1)
				path->start = i;
			if (link[i][j] == 1)
				path->start_nb++;
			else if (link[i][j] == 3)
				path->end_nb++;
			else if (link[i][j] == 2)
				break ;
			j++;
		}
		i++;
	}
	if (path->end_nb == 0 || path->start_nb == 0)
		return (-1);
	return (path->start_nb <= path->end_nb ? path->start_nb : path->end_nb);
}

int		look_for_end(t_room *room)
{
	int i;

	i = 0;
	while (i < room->nb)
	{
		if (ft_memchr((room->link[i]), 3, room->nb) != NULL)
				return (i);
		i++;
	}
	return (-1);
}

void		swap_path(int **path1, int **path2)
{
	int *tmp;

	tmp = *path1;
	*path1 = *path2;
	*path2 = tmp;
}

void	do_rev(int *path, int len)
{
	int a;
	int b;
	int c;

	b = len - 1;
	a = 0;
	while (a < b)
	{
		c = path[a];
		path[a] = path[b];
		path[b] = c;
		b--;
		a++;
	}
}

void		rev_slc(t_slc *slc)
{
	t_slc	*tmp;
	int	i;

	tmp = slc;
	if (tmp->nb_slc > 0)
	{
		i = 0;
		while (i < tmp->nb_slc)
		{
			do_rev(tmp->path[i], tmp->len_path[i]);
			i++;
		}
	}
}
