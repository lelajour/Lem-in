/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:11:50 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/07 04:00:21 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

t_end	*path_end_init(t_path *path, int nb_ant, int nb_room)
{
	int		i;
	t_end	*zend;

	i = 0;
	zend = malloc(sizeof(t_end) * 1);
	zend->heat = ft_imemset(ft_memalloc(path->nb_path), -1, path->nb_path);
	zend->nb_path = 0;
	zend->max_len = 2;
	zend->path = malloc(sizeof(int*) * nb_room);
	while (i < nb_room)
	{
		zend->path[i] = ft_imemset(ft_memalloc(nb_room), -1, nb_room);
		i++;
	}
	zend->heat_max = 0;
	zend->ant = ft_imemset(ft_memalloc(path->nb_path), -1, path->nb_path);
	zend->nb_ant = nb_ant;
	zend->msize = 1;
	zend->scotch = nb_room;
	zend->next = NULL;
	return (zend);
}

void	reajust_end(t_end *tmp, int nb)
{
	int		**tab;
	int		i;

	tmp->msize += 1;
	i = 0;
	tab = malloc(sizeof(int*) * (tmp->msize * nb));
	while (i < (tmp->msize * nb))
	{
		tab[i] = ft_memalloc(nb);
		if (i < ((tmp->msize - 1) * nb))
			ft_imemcpy(tab[i], tmp->path[i], tmp->max_len);
		else
			ft_imemset(tab[i], -1, nb);
		i++;
	}
	ft_clear_int_tab(tmp->path, (tmp->msize - 1) * nb);
	tmp->path = tab;
}

int		no_dup(int p1, int p2, t_slc *slc)
{
	int i;
	int j;

	i = 1;
	while (i < slc->len_path[p1] - 1)
	{
		j = 1;
		while (j < slc->len_path[p2] - 1)
		{
			if (slc->path[p2][j] == slc->path[p1][i])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int not_did(int i, int j, t_end *tmp, int nb)
{
	int t;
	int	*tab;

	t = 0;
	tab = ft_memalloc(2);
	tab[0] = i;
	tab[1] = j;
	while (t < tmp->nb_path)
	{
		if (tab[0] == tmp->path[t][0] && tab[1] == tmp->path[t][1])
		{
			free(tab);
			return (-1);
		}
		else if (tab[0] == tmp->path[t][1] && tab[1] == tmp->path[t][0])
		{
			free(tab);
			return (-1);
		}
		t++;
	}
	free(tab);
	if (tmp->nb_path + 1 == (nb * tmp->msize))
		reajust_end(tmp, nb);
	return (1);
}

void	path_finding(t_path *path, t_room *room, t_ant *ant)
{
	int	i;
	int	j;

	if (path->zend == NULL)
		path->zend = path_end_init(path, ant->nb_ant, room->nb);
	i = -1;
	while (++i < path->slc->nb_slc)
	{
		j = -1;
		while (++j < path->slc->nb_slc)
		{
			if (j + 1 < path->slc->nb_slc && j == i)
				j += 1;
			if (no_dup(i, j, path->slc) == 1 &&
			 not_did(i, j, path->zend, room->nb) == 1)
			{
				ft_printf("[%d]|[%d]\n", i, j);
				path->zend->path[path->zend->nb_path][0] = i;
				path->zend->path[path->zend->nb_path][1] = j;
				path->zend->nb_path++;
				if (path->slc->len_path[j + 1] > path->slc->len_path[j])
					break ;
			}
		}
	}
	ft_printf("combi done : 2 paths\n");
	do_the_rest(path, room, ant);
}
