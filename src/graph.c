/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   graph.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 16:57:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 17:36:24 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


// ################################################
// #IL EST VRAIMENT SUPER CE LEMIN
// # EN PLUS FAIT PAR UN BG TKT SALUT
// ###############################################
// #
// #
// #

#include "../header/lemin.h"

char		**realloc_tab(char **tab, int i)
{
	static char	**tmp;
	int					y;

	y = 0;
	tmp = ft_memalloc(i);
	while (y < i)
	{
		tmp[y] = ft_strdup(tab[y]);
		free(tab[y]);
		y++;
	}
	free(tab);
	return (tmp);
}

static t_room *take_adress(t_room *room, char *line, char *str)
{
	t_room *tmp;

	tmp = room;
	while (tmp->next != NULL)
	{
		if (ft_strstr(line, room->name) && !ft_strstr(str, room->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static char *chearch_room_name(int i, t_room *room)
{
	t_room	*tmp;
	char		*name;
	int			len;

	len = 0;
	tmp = room;
	while (len++ != i)
		tmp = tmp->next;
	name = tmp->name;
	return (name);
}

t_room **set_room_link(char *tab[], int i, int *itab, t_room *room)
{
	t_room	**link;
	char		*str;
	int			y;
	int			x;

	y = 0;
	x = 0;
	char *svp;
	str = chearch_room_name(i, room);
	if (!(link = (t_room**)malloc(sizeof(t_room*) * itab[i])))
		exit(1);
	while (y < room->nb_link)
	{
		if ((svp = ft_strstr(str, tab[y])))
			if ((link[x++] = take_adress(room, tab[y], str)) == NULL)
				exit(1);
		ft_printf("[%p][%d][%s]--[%s]\n", &link[x], x, tab[y], svp);
		y++;
	}
	return (link);
}
