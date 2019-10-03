/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   link_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:13:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 17:27:11 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static void create_graph(char **tab, int *itab, t_room *room, int nb_link)
{
	t_room	*tmp;
	int			i;
	int			y;

	tmp = room;
	i = 0;
	y = 0;
	room->nb_link = nb_link;
	while (tmp->next != NULL)
	{
		tmp->link = set_room_link(tab, i, itab, room);
		// while (y < itab[i])
		// 	ft_printf("""""[%p]""""\n", tmp->link[y++]);
		// ft_printf("---------");
		tmp = tmp->next;
		i++;
	}
	ft_memdel((void**)&itab);
	// ft_clear_tab(tab, room->nb);
}

static int *del_ret(char *one, char *two, int *ret)
{
	ft_strdel(&one);
	ft_strdel(&two);
	return (ret);
}

static int *initlfl(int *one, int *two)
{
	int	*ret;

	ret = ft_memalloc(2);
	*one = 1;
	*two = 1;
	return (ret);
}

static int	*look_for_links(char *line, t_room *tmp)
{
	char *name;
	char *name2;
	int *ret;
	int	one;
	int	two;

	name = ft_strcdup(line, '-');
	name2 = ft_strdup(line + ft_strclen(line, '-') + 1);
	ret = initlfl(&one, &two);
	while (tmp->next != NULL)
	{
		if (!ft_strcmp(name, tmp->name) || !ft_strcmp(name2, tmp->name))
		{
			if (one != 1 || two != 1)
				return (del_ret(name, name2, ret));
			if (ft_strcmp(name, tmp->name) == 0)
				one = 0;
			else
				two = 0;
		}
		ret[0] += one;
		ret[1] += two;
		tmp = tmp->next;
	}
	return (ret);
}

void	set_graph(char *line, t_room *room)
{
	t_room				*tmp;
	int						*ret;
	static	int		i = 0;
	static	int		*itab = NULL;
	static	char	*tab[999];

	tmp = room;
	ret = NULL;
	if (!itab)
		itab = ft_memalloc(room->nb);
	if (line == NULL)
		create_graph(tab, itab, room, i);
	else if ((ret = look_for_links(line, tmp)) != 0)
	{
		tab[i] = ft_strdup(line);
		itab[ret[0]] += 1;
		itab[ret[1]] += 1;
		i++;
		// realloc_tab(tab, i);
		ft_memdel((void**)&ret);
	}
	// int y = 0;
	// ft_printf("%s\n", line);
	// while (y < room->nb)
	// 	ft_printf("[%d] ", itab[y++]);
	// ft_printf("\n");
}
