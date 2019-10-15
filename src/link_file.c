/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   link_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:13:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 08:16:18 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static int **link_init(int nb)
{
	int i;
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

static int	*get_room1(char *line, t_room *room)
{
	int		*room1;
	int		i;
	char	*name;

	room1 = ft_memalloc(2);
	name = ft_strcdup(line, '-');
	//printf("ici->%s\n", name);
	i = 0;
	while (room->next != NULL)
	{
		//printf("%s -----> %d ---> %s\n", room->name, room->pos, name);
		if (ft_strcmp(name, room->name) == 0)
		{
			room1[0] = i;
			room1[1] = room->pos + 1;
		}
		//printf("%d--%d\n", room1[0], room1[1]);
		i++;
		room = room->next;
	}
	//printf("\n");
	ft_strdel(&name);
	return (room1);
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
		//printf("%s -----> %d ---> %s\n", room->name, room->pos, name);
		if (ft_strcmp(name, room->name) == 0)
		{
			room2[0] = i;
			room2[1] = room->pos + 1;
		}
		
		i++;
		room = room->next;
	}
	//printf("\n");
	ft_strdel(&name);
	return (room2);
}

static int **complete_graph(char *line, t_room *room, int **link)
{
	int		*room1;
	int		*room2;

	
	room1 = get_room1(line, room);
	room2 = get_room2(line, room);
	//printf("%d-%d-%d\n", room1[0], room2[0], room1[1]);
	//printf("room1 --> %d\n", room1[0]);
	//printf("room2 --> %d\n\n", room2[0]);
	if ((room2[1] == 1 || room2[1] == 3) && room1[1] == 2)
		room1[1] = room2[1];
	if (link[room1[0]][room2[0]] == 0)
		link[room1[0]][room2[0]] = room1[1];
	if (link[room2[0]][room1[0]] == 0)
		link[room2[0]][room1[0]] = room1[1];
	ft_memdel((void**)&room1);
	ft_memdel((void**)&room2);
	return (NULL);
}

int		**set_graph(char *line, t_room *room)
{
	static int	**link = NULL;
	
	int 	nb_room;
	t_room 	*tmp_room;

	nb_room = room->nb;
	if (line == NULL)
	{
		if (link == NULL)
			room->error = 404;
		else
		{
			int i = 0;
			int ret = 0;
			//ft_printf("    0   1   2   3   5   4\n");
			tmp_room = room;
			while (i < nb_room)
			{
				ft_printf("    %s", room->name);
				room = room->next;
				i++;
			}
			room = tmp_room;
			ft_printf("\n");
			i = 0;
			while (i < nb_room)
			{
				ret = 0;
				ft_printf("%s| ", room->name);
				while (ret < nb_room)
					ft_printf("[%02d] ", link[i][ret++]);
				i++;
				ft_printf("\n");
				room = room->next;
			}
		}
		return (link);
	}
	else if (link == NULL)
		link = link_init(room->nb);
	

	complete_graph(line, room, link);
	
	return (NULL);
}