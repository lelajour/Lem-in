/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 16:57:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 10:50:42 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static t_slc	*sort_slc(t_slc *slc, int *valid_path)
{
	t_slc	*tmp;
	int		i;

	tmp = slc;
	i = 0;
	if (tmp->nb_slc != 0)
	{
		*valid_path += 1;
		while (i < tmp->nb_slc - 1)
		{
			if (tmp->len_path[i] > tmp->len_path[i + 1])
			{
				swap_path(&tmp->path[i], &tmp->path[i + 1]);
				ft_swap(&tmp->len_path[i], &tmp->len_path[i + 1]);
				i = -1;
			}
			i++;
		}
	}
	return (slc);
}

static int		get_next_room(t_room *r, t_path *pa, int i)
{
	int	y;
	int	node;

	y = -1;
	node = pa->utils->first->tab[pa->utils->first->len - 1];
	while (i < r->nb)
	{
		if (r->link[node][i] != 0 && r->link[node][i] != -1)
		{
			if (pa->utils->did[i] != 1)
				return (i);
		}
		i++;
	}
	return (-1);
}

int				*copy_path(t_path *path, int node)
{
	int	i;
	int	*tab;

	i = 0;
	tab = ft_memalloc(path->utils->first->len + 1);
	while (i < path->utils->first->len)
	{
		tab[i] = path->utils->first->tab[i];
		i++;
	}
	tab[i] = node;
	return (tab);
}

void			bfs_algo(t_path *path, t_room *room, t_ant *ant)
{
	int		i;

	i = 0;
	if (path->utils->first->tab[path->utils->first->len - 1] == path->rend)
	{
		path->utils->count++;
		path->utils->did[i] = 0;
		save_path(path, room->nb, path->utils->first->tab);
	}
	else if (path->utils->count < 25)
	{
		while ((i = get_next_room(room, path, i)) != -1)
		{
			if (i != path->rend)
				path->utils->did[i] = 1;
			path->utils->file->next = add_path(i, path);
			path->utils->file = path->utils->file->next;
			i++;
		}
	}
	path->utils->first = new_fill(path->utils->first, path->utils);
	path->utils->index++;
	if (path->utils->first != NULL && path->utils->first->len < path->limit + 5)
		bfs_algo(path, room, ant);
}

t_path			*check_if_connected(t_room *room, t_ant *ant)
{
	t_path	*path;
	int		y;

	y = 0;
	if ((path = init_path(room->link, room)) == NULL)
		return (NULL);
	path->slc = init_slc(room, path);
	path->utils = init_utils(path);
	if (room->limit != -1)
		path->limit = room->limit;
	while (y < path->lentd && init_t_bfs(path->utils, path, y) != 0)
	{
		path->utils->count = 0;
		bfs_algo(path, room, ant);
		ft_ibzero(path->utils->did, path->utils->nb_room);
		path->utils->did[path->rstart] = 1;
		y++;
	}
	path->valid_path = 0;
	path->slc = sort_slc(path->slc, &path->valid_path);
	if (path->rev == 1)
		rev_slc(path->slc);
	path_finding(path, room, ant);
	return (path);
}
