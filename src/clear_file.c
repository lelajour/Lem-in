/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/14 17:15:22 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/02 16:34:24 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

int		ft_404(t_ant *ant, t_room *room)
{
	if ((room && room->error == 404) || ant == NULL)
		ft_putstr("Wrong map file\n");
	else if (room->error == 101)
		ft_putstr("2 start or end room, abording\n");
	ft_clear(ant, room);
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
			free(room->link);
		tmp = room->next;
		free(room);
		room = tmp;
	}
}