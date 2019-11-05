/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/14 17:15:22 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 21:31:09 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static void		ft_clear_path(t_path *path)
{
	t_slc *tmp;

	tmp = NULL;
	if (path->path != NULL)
		free(path->path);
	if (path->did != NULL)
		free(path->did);
	if (path->to_do != NULL)
		free(path->to_do);
	if (path->slc != NULL)
	{
		while (path->slc != NULL)
		{
			if (path->slc->path != NULL)
				ft_clear_int_tab(path->slc->path, path->slc->nb_slc);
			if (path->slc->len_path != NULL)
				free(path->slc->len_path);
			tmp = path->slc;
			path->slc = path->slc->next;
			free(tmp);
		}
	}
	free(path);
}

int		ft_404(t_ant *ant, t_room *room, t_path *path)
{
	if ((room && room->error == 404) || ant == NULL)
		ft_putstr("Wrong map file\n");
	else if (room->error == 101)
		ft_putstr("2 start or end room, abording\n");
	else if (path && path->valid_path == 0)
		ft_putstr("No valid path, abording\n");
	// ft_clear_path(room->soluce);
	ft_clear(ant, room);
	if (path != NULL)
		ft_clear_path(path);
	exit(0);
}

void	ft_clear(t_ant *ant, t_room *room)
{
	void *tmp;

	tmp = NULL;
	while (ant != NULL)
	{
		if (ant->name)
			free(ant->name);
		if (ant->room)
			free(ant->next_room);
		if (ant->next_room)
			free(ant->next->room);
		tmp = ant->next;
		free(ant);
		ant = tmp;
	}
	while (room != NULL)
	{
		if (room->name)
			free(room->name);
		if (room->link)
			ft_clear_int_tab(room->link, room->nb);
		tmp = room->next;
		free(room);
		room = tmp;
	}
}
