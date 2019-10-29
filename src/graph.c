/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   graph.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 16:57:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 21:22:28 by lelajour    ###    #+. /#+    ###.fr     */
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

// static int		check_if_visited(int room, t_path *path)
// {
// 	int	j;
//
// 	j = 0;
// 	while (j < path->len_did)
// 	{
// 		if (room == path->did[j])
// 			return (-1);
// 		j++;
// 	}
// 	return (1);
// }

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

// static int	*del_first(int *to_do, t_path *path)
// {
// 	int	i;
//
// 	i = 0;
// 	while (to_do[i] && i < path->len_td)
// 	{
// 		to_do[i] = to_do[i + 1];
// 		i++;
// 	}
// 	path->len_td -= 1;
// 	return (to_do);
// }

void	bfs_algo(t_path *path, t_room *room, int pos, int node)
{
	int		i;
	int		nb;

	i = -1;
	path->did[node] = 1;
	path->path[pos][path->len_path++] = node;
	if (node == path->end)
	{
		int y = -1;
		while (++y < path->len_path)
			ft_printf("[%d]|", path->path[pos][y]);
		ft_printf("\n");
	}
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
	int		checkd;
	t_path	*path;

	checkd = 0;
	pos = 0;
	if ((path = init_path(room->link, room)) == NULL)
		return (NULL);
	path->len_did = 1;
	while (pos < 1)
	{
		path->did[path->start] = 1;
		path->len_path = 0;
		bfs_algo(path, room, pos, 1);
		pos++;
	}
	return (path);
}
