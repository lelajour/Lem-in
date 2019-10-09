/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 12:56:35 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/02 16:22:33 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static int		check_if_tube(char *line, t_room *room)
{
	t_room	*tmp;
	char		*str;
	int			nb;

	nb = 1;
	tmp = room;
	str = ft_strcdup(line, '-');
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
		{
			nb++;
			ft_strdel(&str);
			if (nb == 3)
				return (0);
			str = ft_strdup(line + ft_strclen(line, '-') + 1);
			tmp = room;
		}
		else
			tmp = tmp->next;
	}
	if (str)
		ft_strdel(&str);
	return (1);
}

static int	check_if_room(char *line, t_room *tmp, t_room *room)
{
	int	c;
	int	i;
	int	count;

	c = ' ';
	i = 0;
	count = 0;
	while (line[i] && count <= 2)
	{
		if (line[i] == ' ')
			count++;
		if (count >= 1 && line[i] != ' ')
			if ((line[i] < 48 || line[i] > 57))
			{
				tmp->error = 404;
				return (1);
			}
		i++;
	}
	if (count != 2)
	{
		tmp->error = 404;
		return (1);
	}
	return (room_check_if_double(line, room));
}

int		get_room_width(char *line)
{
	int	i;

	i = ft_strlen(line);
	while (line[i] != ' ')
		i--;
	return (ft_atoi(&line[i]));
}

static t_room	*lemin_parsing(char *line, t_room *tmp, t_room *room)
{
	int len;

	len = ft_strclen(line, ' ');
	if (line[0] == '#')
		tmp = room_check(tmp, line);
	else if (!ft_strchr(line, '-') && check_if_room(line, tmp, room) == 0)
	{
		tmp->name = ft_strsub(line, 0, len);
		tmp->len = ft_atoi(line + len);
		tmp->width = get_room_width(line);
		tmp->next = room_struct_allocation();
		if (tmp->len < 0 || tmp->width < 0)
			room->error = 404;
		tmp = tmp->next;
	}
	else if (check_if_tube(line, room) == 0)
		set_graph(line, room);
	free(line);
	return (tmp);
}

void		vhevklist(t_room *room)
{
	int i;

	i = 0;
	while (room->next != NULL)
	{
		ft_printf("%d|[%p][%s]\n", i++, &*room, room->name);
		room = room->next;
	}
	ft_printf("-------------------\n");
}

int		main(void)
{
	char	*line;
	t_ant	*ant;
	t_room *room;
	t_room *tmp;

	line = NULL;
	ant = find_nb_ant();
	room = room_struct_allocation();
	tmp = room;
	while (get_next_line(0, &line) == 1)
	{
		vhevklist(room);
		tmp = lemin_parsing(line, tmp, room);
		if (tmp->error != 0 || room->error != 0)
			return (ft_404(ant, room));
	}
	set_graph(NULL, room);
	ft_printf("nombre de room = %d\n", room->nb);
	ft_404(ant, room);
	return (0);
}
