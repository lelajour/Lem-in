/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:05:53 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/14 07:05:18 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

char	*get_room(int index, t_room *room)
{
	int		i;
	t_room	*tmp;

	i = -1;
	tmp = room;
	while (++i < index)
		tmp = tmp->next;
	return (tmp->name);
}

char	**get_room_name(t_end *end, t_slc *slc, t_room *room)
{
	int		i;
	int		j;
	int		index;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char*) * room->nb);
	while (i < end->rappel)
	{
		j = 1;
		while (j < slc->len_path[end->path[0][i]])
		{
			index = slc->path[end->path[0][i]][j];
			tab[index] = get_room(index, room);
			j++;
		}
		i++;
	}
	return (tab);
}


void	free_shit(char **name, int **move, t_end *end)
{
	int i;

	i = 0;
	ft_clear_int_tab(move, end->nb_ant);
	free(name);
}
