/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_slc_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:09:02 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/14 12:02:13 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

t_slc	*init_slc(t_room *room)
{
	t_slc	*slc;
	t_slc	*tmp;

	if (!(slc = malloc(sizeof(t_slc) * 1)))
		return (NULL);
	tmp = slc;
	if (!(slc->path = malloc(sizeof(int*) * 200)))
		return (NULL);
	slc->len_path = ft_imemset(ft_memalloc(200), 0, 200);
	slc->nb_slc = 0;
	slc->nb_room = room->nb;
	slc->min = INT_MAX;
	slc->mallocsize = 200;
	return (tmp);
}

static void		realloc_slc_path(t_slc *slc)
{
	int		**new;
	int		*new_len;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(int*) * (200 + slc->nb_slc))))
		exit(-1);
	if (!(new_len = malloc(sizeof(int) * (200 + slc->nb_slc))))
		exit(-1);
	while (i < slc->nb_slc - 1)
	{
		new[i] = ft_itabdup(slc->path[i], slc->len_path[i]);
		new_len[i] = slc->len_path[i];
		i++;
	}
	ft_clear_int_tab(slc->path, slc->nb_slc - 1);
	free(slc->len_path);
	slc->path = new;
	slc->len_path = new_len;
	slc->mallocsize = 200 + slc->nb_slc;
}

void	save_path(t_path *path, int nb)
{
	int tmp;

	(void)nb;
	tmp = 0;
	path->slc->nb_slc += 1;
	tmp = path->slc->nb_slc - 1;
	if (path->slc->nb_slc == path->slc->mallocsize)
		realloc_slc_path(path->slc);
	if (path->slc->path)
	{
		path->slc->path[tmp] = ft_itabdup(path->path, path->len_path);
		path->slc->len_path[tmp] = path->len_path;
	}
	if (path->len_path < path->slc->min)
		path->slc->min = path->len_path;
}

static int		*to_do_init(int **link, t_room *room, t_path *path)
{
	int	j;
	int	i;
	int	tmp;
	int	start;
	int	*to_do;

	i = 0;
	tmp = 0;
	start = path->start_nb <= path->end_nb ? 1 : 3;
	path->rev = path->start_nb <= path->end_nb ? 0 : 1;
	if (!(to_do = malloc(sizeof(int) * path->nb_path)))
		return (NULL);
	while (i < room->nb)
	{
		j = 0;
		while (j < room->nb)
		{
			if (link[i][j] == start)
				to_do[tmp++] = j;
			j++;
		}
		i++;
	}
	path->end = look_for_end(room);
	return (to_do);
}

t_path	*init_path(int **link, t_room *room)
{
	int		nb_path;
	t_path	*path;

	if (!(path = malloc(sizeof(t_path) * 1)))
		return (NULL);
	nb_path = 0;
	path->nb_path = 0;
	path->start = -1;
	path->end = 0;
	path->end_nb = 0;
	path->rev = 0;
	path->start_nb = 0;
	if ((nb_path = ft_start_chr(link, room->nb, path)) != -1)
	{
		path->nb_path = nb_path;
		path->path = ft_imemset(ft_memalloc(room->nb), -2, room->nb);
		path->did = ft_imemset(ft_memalloc(room->nb), -1, room->nb);
		path->to_do = to_do_init(link, room, path);
		path->rend = path->start_nb <= path->end_nb ? path->end : path->start;
		path->rstart = path->start_nb <= path->end_nb ? path->start : path->end;
		path->slc = NULL;
		path->ok = INT_MAX;
		path->zend = NULL;
	}
	return (path);
}
