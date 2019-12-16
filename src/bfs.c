/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:57:36 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/14 22:31:29 by lelajour         ###   ########.fr       */
/*                                                                            */
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

static int		*get_next_room(int room, t_room *r, int *i)
{
	int		*passage;
	int		len;
	int		ret;

	ret = 0;
	len = 0;
	passage = NULL;
	if (passage == NULL)
	{
		while (ret < r->nb)
		{
			if (r->link[room][ret] != 0 && r->link[room][ret] != -1)
				len++;
			ret++;
		}
		passage = init_passage(r->link[room], r->nb, len + 1);
	}
	if (passage[*i] < 0)
	{
		free(passage);
		return (NULL);
	}
	else
		return (passage);
	return (NULL);
}

void	bfs_algo(t_path *path, t_room *room, t_ant *ant, int node)
{
	int		i;
	int		*taille;

	i = 0;
	path->did[node] = 1;
	path->path[path->len_path++] = node;
	if (node == path->rend)
	{
		upgrade_mtc(room->link, path, room->nb);
		save_path(path, room->nb);
	}
	else if ((taille = get_next_room(node, room, &i)) != NULL)
	{
		while (taille[i] != -1)
		{
			if (path->did[taille[i]] != 1)
				bfs_algo(path, room, ant, taille[i]);
			i++;
		}
		free(taille);
	}
	path->len_path--;
	path->did[node] = -1;
}

t_path	*check_if_connected(t_room *room, t_ant *ant)
{
	t_path	*path;
	t_slc *tmp;

	if ((path = init_path(room->link, room)) == NULL)
		return (NULL);
	path->slc = init_slc(room);
	tmp = path->slc;
	int y = -1;
	ft_printf("La salle de départ est %d et la salle de fin est %d (rev : %d)\n", path->rstart, path->rend, path->rev);
	ft_printf("Nous sommes les salles connecté a la salle start :\n");
	while (++y < path->nb_path)
		ft_printf("[%d]|", path->to_do[y]);
	ft_printf("\n-------------\n");
	ft_printf("Nombre de paths = %d\n", path->nb_path);
	path->did[path->rstart] = 1;
	path->len_path = 0;
	bfs_algo(path, room, ant, path->rstart);
	ft_memset(path->did, -1, room->nb);
	path->valid_path = 0;
	path->slc = sort_slc(path->slc, &path->valid_path);
	if (path->rev == 1)
		rev_slc(path->slc);
	path_finding(path, room, ant);
	tmp = path->slc;
	// int i = 0;
	ft_printf("Nous sommes les paths partant de start(%d) :\n", path->rstart);
	// if (tmp->nb_slc != 0)
	// {
		// while (i < tmp->nb_slc)
		// {
			// y = 0;
			// ft_printf("%d |", i);
			// while (y < tmp->len_path[i])
				// ft_printf("[%d]|", tmp->path[i][y++]);
			// ft_printf("%d\n", tmp->len_path[i]);
			// i++;
		// }
	// }
	return (path);
}
