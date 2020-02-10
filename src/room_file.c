/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:53:26 by lelajour          #+#    #+#             */
/*   Updated: 2020/02/02 12:53:38 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/lemin.h"

static int	del_scotch(t_room *room, char *str, int err)
{
	if (err == 1)
		room->error = 404;
	ft_strdel(&str);
	return (1);
}

t_room		*room_check(t_room *tmp, char *line, int *error)
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
	else if (ft_strncmp(line, "#Here is", 8) == 0)
		tmp->limit = check_if_limit(line);
	if (end > 1 || start > 1)
		*error = 101;
	return (tmp);
}

int			room_check_if_double(char *line, t_room *room)
{
	int		width;
	int		len_room;
	int		len;
	char	*str;
	t_room	*tmp;

	len = ft_strclen(line, ' ');
	width = get_room_width(line);
	len_room = ft_atoi(line + len);
	str = ft_strsub(line, 0, len);
	tmp = room;
	if (line[0] == 'L')
		return (del_scotch(room, str, 1));
	while (tmp->next != NULL)
	{
		if (ft_strcmp(str, tmp->name) == 0)
			return (del_scotch(room, str, 0));
		if (width == tmp->width && len_room == tmp->len)
			return (del_scotch(room, str, 0));
		tmp = tmp->next;
	}
	ft_strdel(&str);
	room->nb += 1;
	return (0);
}

t_room		*room_struct_allocation(void)
{
	t_room *room;

	room = malloc((sizeof(t_room)));
	room->name = NULL;
	room->nb = 0;
	room->limit = -1;
	room->connex = 0;
	room->pos = INT_MAX - 2;
	room->len = 0;
	room->big = 0;
	room->width = 0;
	room->nb_sec = 0;
	room->ant = 0;
	room->comb = 0;
	room->error = 0;
	room->link = NULL;
	room->next = NULL;
	return (room);
}
