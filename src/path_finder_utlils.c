/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utlils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 23:56:23 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/07 07:46:03 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

int		check_if_here(int *path, int tmp, int len)
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
int		checkndup(int path, t_end *end, int test, int nb)
{
	int *tab;
	int	i;
	int j;
	int	count;

	i = 0;
	count = 0;
	tab = ft_memalloc(nb);
	ft_imemset(tab, 0, nb);
	tab[test] = 1;
	while (i < end->max_len)
		tab[end->path[path][i++]] = 1;
	i = -1;
	while (++i < end->next->nb_path)
	{
		j = -1;
		count = 0;
		while (++j < end->next->max_len)
		{
			if (tab[end->next->path[i][j]] == 1)
				count++;
			if (count == end->next->max_len)
				return (-1);
		}
	}
	free(tab);
	return (1);
}

int		combinaison(t_slc *slc, t_end *tmp, int test, int path)
{
	int i;
	t_end *tmp2;

	i = 0;
	tmp2 = tmp->next;
	if (check_if_here(tmp->path[path], test, tmp->max_len) == -1)
		return (-1);
	else
	{
		while (i < tmp->max_len)
		{
			if (checkndup(path, tmp, test, slc->nb_slc) == -1)
				return (-1);
			if (no_dup(test, tmp->path[path][i], slc) == -1)
				return (-1);
			i++;
		}
		if (tmp2->nb_path + 1 == (tmp2->scotch * tmp2->msize))
			reajust_end(tmp2, tmp2->scotch);
		ft_imemcpy(tmp2->path[tmp2->nb_path], tmp->path[path], tmp->max_len);
		tmp2->path[tmp2->nb_path][tmp->max_len] = test;
		tmp2->nb_path++;
		i = 0;
		while (i < tmp->max_len)
			ft_printf("[%d]|", tmp->path[path][i++]);
		ft_printf("[%d]", test);
		ft_printf("\n");
	}
	return (1);
}

void	do_the_rest(t_path *path, t_room *room, t_ant *ant)
{
	int		i;
	int		i_slc;
	int		j;
	t_end	*tmp;

	i = 2;
	tmp = path->zend;
	while (tmp->nb_path != 0)
	{
		j = 0;
		tmp->next = path_end_init(path, ant->nb_ant, room->nb);
		tmp->next->max_len = tmp->max_len + 1;
		while (j < tmp->nb_path)
		{
			i_slc = 0;
			while (i_slc < path->slc->nb_slc &&
				combinaison(path->slc, tmp, i_slc, j) != 1)
				++i_slc;
			j++;
		}
		i++;
		ft_printf("combi done : %d paths\n", i);
		tmp = tmp->next;
	}
}
