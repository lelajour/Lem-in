/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   link_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:13:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:29:27 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static int	**link_init(int nb)
{
	int	i;
	int	**link;

	i = 0;
	if (!(link = malloc(sizeof(int*) * nb)))
		return (NULL);
	while (i < nb)
	{
		link[i] = malloc(sizeof(int) * nb);
		ft_ibzero(link[i], nb);
		link[i][i] = -1;
		i++;
	}
	return (link);
}

static int	*get_room2(char *line, t_room *room)
{
	int		*room2;
	int		i;
	char	*name;

	room2 = ft_memalloc(2);
	name = ft_strdup(line + ft_strclen(line, '-') + 1);
	i = 0;
	while (room->next != NULL)
	{
		if (ft_strcmp(name, room->name) == 0)
		{
			room2[0] = i;
			room2[1] = room->pos + 1;
		}
		i++;
		room = room->next;
	}
	ft_strdel(&name);
	return (room2);
}

static int	*get_room1(char *line, t_room *room)
{
	int		*room1;
	int		i;
	char	*name;

	room1 = ft_memalloc(2);
	name = ft_strcdup(line, '-');
	i = 0;
	while (room->next != NULL)
	{
		if (ft_strcmp(name, room->name) == 0)
		{
			room1[0] = i;
			room1[1] = room->pos + 1;
		}
		i++;
		room = room->next;
	}
	ft_strdel(&name);
	return (room1);
}

int			**set_graph(char *line, t_room *r)
{
	static int	**link = NULL;
	int			*room1;
	int			*room2;

	if (line == NULL)
	{
		if (link == NULL || ft_start_chr2(link, r->nb))
			r->error = 404;
		if (r->connex != 0 && r->connex > (r->connex * 0.10) + r->nb)
			r->big += 1;
		ft_printf("\n");
		return (link);
	}
	else if (link == NULL)
		link = link_init(r->nb);
	room1 = get_room1(line, r);
	room2 = get_room2(line, r);
	if (link[room1[0]][room2[0]] == 0)
		link[room1[0]][room2[0]] = room1[1];
	if (link[room2[0]][room1[0]] == 0)
		link[room2[0]][room1[0]] = room2[1];
	ft_memdel((void**)&room1);
	ft_memdel((void**)&room2);
	r->connex += 1;
	return (NULL);
}
