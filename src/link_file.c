/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   link_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:13:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 17:18:40 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

// static void fill_itab(int *ret, int *itab, int nb)
// {
// 	(void)nb;
// 	(void)itab;
// 	(void)ret;
// 	ft_printf("[%d]|[%d]", ret[0], ret[1]);
//
// }

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
	int					*ret;
	static	int		*itab = NULL;
	static	char	**tab = NULL;
	static	int		i = 0;

	tmp = room;
	ret = NULL;
	if (!itab)
		itab = ft_memalloc(room->nb);
	if (!tab)
		if (!(tab = malloc(sizeof(char*) * room->nb)))
			exit(-1);
	// if (line == NULL)
	// 	create_graph(tab, itab, room);
	if ((ret = look_for_links(line, tmp)) != 0 && i < room->nb)
	{
		tab[i] = ft_strdup(line);
		itab[ret[0]] += 1;
		itab[ret[1]] += 1;
		i++;
		ft_memdel((void**)&ret);
	}
}
