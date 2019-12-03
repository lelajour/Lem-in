/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_finder_utlils.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 23:56:23 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 17:35:44 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

int		is_new_path(t_path *path)
{
	int	i;
	int	room;

	i = 0;
	room = path->path[1];
	while (i < path->zend->nb_path)
	{
		if (room == path->zend->path[i][1])
			return (-1);
		i++;
	}
	return (1);
}

int		check_if_dup(/*t_path *path*/)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	//while (i < path->end->nb_path)
	//{
	//	path->
	return (0);
}
