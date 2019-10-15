/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   graph.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 16:57:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 16:16:26 by lelajour    ###    #+. /#+    ###.fr     */
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

// int		check_if_visited(t_path *path, int **link, int pos)
// {
// 	int	did;
//
// 	did = 0;
// 	while ()
//
// }

t_path	*check_if_connected(t_room *room)
{
	int			pos;
	t_path	*path;

	pos = 0;
	if ((path = init_path(room->link, room)) == NULL)
		return (NULL);
	path->len_did = 1;
	while (pos < path->nb_path)
	{
		int y = 0;
		while (y < 15)
			ft_printf("[%d]|", path->to_do[pos][++y]);
		ft_printf("\n");
		// if (fonction cool == -1)
		// 	path->path[pos][0] = -1;
		pos++;
	}
	return (path);
}
