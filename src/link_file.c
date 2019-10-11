/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   link_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:13:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 15:24:50 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

<<<<<<< HEAD
int		check_loop(int *tab , int nb)
{
	int	i;
	int	bulle;

	i = 0;
	bulle = tab[i];
	while (i < nb)
}

static int **link_init(int nb)
{
	int i;
	int	**link;

	i = 0;
=======
// static void create_graph(char **tab, int *itab, t_room *room, int nb_link)
// {
// 	t_room	*tmp;
// 	int			i;
// 	int			y;
//
// 	tmp = room;
// 	i = 0;
// 	y = 0;
// 	room->nb_link = nb_link;
// 	while (tmp->next != NULL)
// 	{
// 		tmp->link = set_room_link(tab, i, itab, room);
// 		// while (y < itab[i])
// 		// 	ft_printf("""""[%p]""""\n", tmp->link[y++]);
// 		// ft_printf("---------");
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	ft_memdel((void**)&itab);
// 	// ft_clear_tab(tab, room->nb);
// }
//
// static int *del_ret(char *one, char *two, int *ret)
// {
// 	ft_strdel(&one);
// 	ft_strdel(&two);
// 	return (ret);
// }
//
// static int *initlfl(int *one, int *two)
// {
// 	int	*ret;
//
// 	ret = ft_memalloc(2);
// 	*one = 1;
// 	*two = 1;
// 	return (ret);
// }
//
// static int	*look_for_links(char *line, t_room *tmp)
// {
// 	char *name;
// 	char *name2;
// 	int *ret;
// 	int	one;
// 	int	two;
//
// 	name = ft_strcdup(line, '-');
// 	name2 = ft_strdup(line + ft_strclen(line, '-') + 1);
// 	ret = initlfl(&one, &two);
// 	while (tmp->next != NULL)
// 	{
// 		if (!ft_strcmp(name, tmp->name) || !ft_strcmp(name2, tmp->name))
// 		{
// 			if (one != 1 || two != 1)
// 				return (del_ret(name, name2, ret));
// 			if (ft_strcmp(name, tmp->name) == 0)
// 				one = 0;
// 			else
// 				two = 0;
// 		}
// 		ret[0] += one;
// 		ret[1] += two;
// 		tmp = tmp->next;
// 	}
// 	return (ret);
// }
//
// void	set_graph(char *line, t_room *room)
// {
// 	t_room				*tmp;
// 	int						*ret;
// 	static	int		i = 0;
// 	static	int		*itab = NULL;
// 	static	char	*tab[999];
//
// 	tmp = room;
// 	ret = NULL;
// 	if (!itab)
// 		itab = ft_memalloc(room->nb);
// 	if (line == NULL)
// 		create_graph(tab, itab, room, i);
// 	else if ((ret = look_for_links(line, tmp)) != 0)
// 	{
// 		tab[i] = ft_strdup(line);
// 		itab[ret[0]] += 1;
// 		itab[ret[1]] += 1;
// 		i++;
// 		// realloc_tab(tab, i);
// 		ft_memdel((void**)&ret);
// 	}
// 	// int y = 0;
// 	// ft_printf("%s\n", line);
// 	// while (y < room->nb)
// 	// 	ft_printf("[%d] ", itab[y++]);
// 	// ft_printf("\n");
// }

static int **link_init(int nb)
{
	int i;
	int	**link;

	i = 0;
>>>>>>> a1b48a609145c9e60f54af4b22584df759e634d8
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
	ft_printf("room 2 name = %s\n", name);
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
	ft_printf("i = %d\npos = %d\n", room2[0], room2[1]);
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
	ft_printf("room 1 name = %s\n", name);
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
	ft_printf("i = %d\npos = %d\n", room1[0], room1[1]);
	ft_strdel(&name);
	return (room1);
}

int		**set_graph(char *line, t_room *room)
{
	static int	**link = NULL;
	int		*room1;
	int		*room2;

	if (line == NULL)
	{
		if (link == NULL)
			room->error = 404;
		else
		{
			int i = 0;
			int ret = 0;
			ft_printf("    0   1   2   3   4   5\n");
			while (i < room->nb)
			{
				ret = 0;
				ft_printf("%d| ", i);
				while (ret < room->nb)
					ft_printf("[%02d]", link[i][ret++]);
				i++;
				ft_printf("\n");
			}
		}
		return (link);
	}
	else if (link == NULL)
		link = link_init(room->nb);
	room1 = get_room1(line, room);
	room2 = get_room2(line, room);
	if (link[room1[0]][room2[0]] == 0)
		link[room1[0]][room2[0]] = room1[1];
	if (link[room2[0]][room1[0]] == 0)
		link[room2[0]][room1[0]] = room2[1];
	ft_memdel((void**)&room1);
	ft_memdel((void**)&room2);
	return (NULL);
}
