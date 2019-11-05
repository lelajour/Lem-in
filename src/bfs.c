/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 16:57:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 14:50:11 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


// ################################################
// #IL EST VRAIMENT SUPER CE LEMIN
// # EN PLUS FAIT PAR UN BG TKT SALUT
// ###############################################
// #
// #
// #

#include "../header/lemin.h"

static void		swap_path(int **path1, int **path2)
{
	int *tmp;

	tmp = *path1;
	*path1 = *path2;
	*path2 = tmp;
}

static t_slc	*sort_slc(t_slc *slc, int *valid_path)
{
	t_slc	*tmp;
	int		i;

	tmp = slc;
	while (tmp != NULL)
	{
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
					i =  -1;
				}
				i++;
			}
		}
		tmp = tmp->next;
	}
	return (slc);
}

static int		get_next_room(int room, int **link, int *i, int nb_room)
{
	while (*i < nb_room)
	{
		if (link[room][*i] != 0 && link[room][*i] != -1)
			return (*i);
		*i += 1;
	}
	return (-1);
}

void	bfs_algo(t_path *path, t_room *room, int pos, int node)
{
	int		i;
	int		nb;

	i = 0;
	path->did[node] = 1;
	path->path[path->len_path++] = node;
	if (node == path->end)
		save_path(path, pos);
	else
	{
		while ((nb = get_next_room(node, room->link, &i, room->nb)) != -1)
		{
			if (path->did[nb] != 1)
				bfs_algo(path, room, pos, nb);
			i++;
		}
	}
	path->len_path--;
	path->did[node] = -1;
}

t_path	*check_if_connected(t_room *room)
{
	int		pos;
	t_path	*path;

	pos = 0;
	if ((path = init_path(room->link, room)) == NULL)
		return (NULL);
	path->slc = init_slc(path->nb_path);
	int y = -1;
	ft_printf("La salle de départ est %d et la salle de fin est %d\n", path->start, path->end);
	ft_printf("Nous sommes les salles connecté a la salle start :\n");
	while (++y < path->nb_path)
		ft_printf("[%d]|", path->to_do[y]);
	ft_printf("\n-------------\n");
	while (pos < path->nb_path)
	{
		path->did[path->start] = 1;
		path->len_path = 0;
		bfs_algo(path, room, pos, path->to_do[pos]);
		pos++;
	}
	path->valid_path = 0;
	path->slc = sort_slc(path->slc, &path->valid_path);
	t_slc *tmp = path->slc;
	int x = 0;
	while (tmp != NULL)
	{
		int i = 0;
		ft_printf("Nous sommes les paths partant de [%d] :\n", path->to_do[x++]);
		if (tmp->nb_slc != 0)
		{
			while (i < tmp->nb_slc)
			{
				y = 0;
				while (y < tmp->len_path[i])
					ft_printf("[%d]|", tmp->path[i][y++]);
				ft_printf("%d\n", tmp->len_path[i]);
				i++;
			}
		}
		ft_printf("\n"),
		tmp = tmp->next;
	}
	ft_printf("nb de path valide : %d\n", path->valid_path);
	return (path);
}
