/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 04:17:59 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:34:13 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

t_bfs			*add_path(int node, t_path *p)
{
	t_bfs *tmp;

	tmp = malloc(sizeof(t_bfs));
	tmp->tab = copy_path(p, node);
	tmp->len = p->utils->first->len + 1;
	tmp->next = NULL;
	return (tmp);
}

int				check_if_other_path(int *tab, t_end *tmp)
{
	static int	i = -1;

	if (i != tmp->actual)
	{
		i = tmp->actual;
		if (tab)
		{
			free(tab);
			tab = NULL;
		}
		return (1);
	}
	return (0);
}

int				sctochhisimo(t_room *room)
{
	room->nb_sec = 0;
	return (1);
}

int				check_if_here(int *path, int tmp, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (path[i] == tmp)
			return (-1);
		i++;
	}
	return (1);
}

void			start_end_connectded(t_end *end, t_slc *slc, t_room *room)
{
	char	*name;
	t_room	*tmp;
	int		index;
	int		i;

	i = 0;
	tmp = room;
	index = slc->path[0][slc->len_path[0] - 1];
	while (index-- >= 0)
	{
		name = tmp->name;
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	while (i < end->nb_ant)
	{
		ft_printf("L%d-%s ", i + 1, name);
		i++;
	}
	ft_printf("\n");
}
