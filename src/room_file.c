/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:53:26 by lelajour          #+#    #+#             */
/*   Updated: 2019/11/30 19:06:16 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/lemin.h"

static int	del_scotch(char *str)
{
	ft_strdel(&str);
	return (1);
}

t_room *room_check(t_room *tmp, char *line, int *error)
{
	static int end = 0;
	static int start = 0;

	tmp->error = 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		start++;
		tmp->pos = 0;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		end++;
		tmp->pos = 2;
	}
	if (end > 1 || start > 1)
		*error = 101;
	return (tmp);
}

int		room_check_if_double(char *line, t_room *room)
{
	int			width;
	int			len_room;
	int			len;
	char		*str;
	t_room	*tmp;

	len = ft_strclen(line, ' ');
	width = get_room_width(line);
	len_room = ft_atoi(line + len);
	str = ft_strsub(line, 0, len);
	tmp = room;
	if (line[0] == 'L')
		return (del_scotch(str));
	while (tmp->next != NULL)
	{
		if (ft_strcmp(str, tmp->name) == 0)
			return (del_scotch(str));
		if (width == tmp->width && len_room == tmp->len)
			return (del_scotch(str));
		tmp = tmp->next;
	}
	ft_strdel(&str);
	room->nb += 1;
	return (0);
}

t_room	*room_struct_allocation(void)
{
	t_room *room;

	room = malloc((sizeof(t_room)));
	room->name = NULL;
	room->nb = 0;
	room->pos = INT_MAX - 2;
	room->len = 0;
	room->width = 0;
	room->ant = 0;
	room->error = 0;
	room->link = NULL;
	room->next = NULL;
	return (room);
}
