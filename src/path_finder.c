/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_finder.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 00:11:50 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 14:20:03 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

t_end *path_end_init(t_path *path, int nb_ant, int nb_room)
{
	int		i;
	t_end	*zend;

	i = 0;
	zend = malloc(sizeof(t_end) * 1);
	zend->heat = ft_imemset(ft_memalloc(path->nb_path), -1, path->nb_path);
	zend->nb_path = 1;
	zend->max_len = malloc(sizeof(int) * path->nb_path);
	zend->path = malloc(sizeof(int*) * path->nb_path);
	while (i < path->nb_path)
	{
		zend->path[i] = ft_imemset(ft_memalloc(nb_room), -1, nb_room);
		if (i == 0)
			ft_imemcpy(zend->path[i], path->path, path->len_path);
		i++;
	}
	zend->heat[0] = (path->len_path * nb_ant) - 1;
	zend->heat_max = zend->heat[0];
	zend->ant = ft_imemset(ft_memalloc(path->nb_path), -1, path->nb_path);
	zend->ant[0] = nb_ant;
	zend->nb_ant = nb_ant;
	zend->max_len[0] = path->len_path;
	return (zend);
}

/*int		split_is_better(t_path *path)
{

}*/

int		test_path(int nb_ant, t_path *path)
{
	int	i;
	int	heat;

	i = 0;
	heat = (nb_ant * path->len_path) - 1;
	if (is_new_path(path) == 1)
	{
		printf("yikes");
		//if (split_is_better(path) == 1)
			// do_split(path);
	}
	// while (i < path-zzend->nb_path)
	// {
	// 	if (heat < path->zend->heat_max && path->zend->nb_path > 1)
	// 	{
	// 		while (i < path->zend->nb_path)
	// 		{
	// 			if (is_better(path, i) == 1)
	// 				return (i);
	// 			i++;
	// 		}
	// 	}
	// 	else if (path->zend->nb_path == 1 && split_is_better(path) == 1)
	// 		return (-1)
	// 	else if (heat < path->zend->heat_max && path->zend->nb_path == 1)
	// 		return (-2);
	// }
	return (-3);
}

void	path_finding(t_path *path, t_room *room, t_ant *ant)
{
	int nb;

	if (path->zend == NULL)
		path->zend = path_end_init(path, ant->nb_ant, room->nb);
	else if ((nb = test_path(ant->nb_ant, path)) >= 0)
	{
		printf("lol");
	}
	// else if (nb == -1)
	// 	split_path(path);
	// else if (nb == -2)
	// 	change_single_path(path);
}
