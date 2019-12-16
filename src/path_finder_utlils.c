/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utlils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 23:56:23 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/16 14:45:46 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

t_end	*head_end_init(int nb_ant, int nb_room)
{
	t_end *tmp;
	int		i;

	i = 1;
	tmp = malloc(sizeof(t_end) * 1);
	tmp->heat = ft_memalloc(1);
	tmp->nb_path = 1;
	tmp->max_len = 1;
	tmp->path = malloc(sizeof(int*) * nb_room);
	tmp->path[0] = ft_memalloc(1);
	while (i < nb_room)
		tmp->path[i++] = NULL;
	tmp->heat_max = 0;
	tmp->ant = ft_memalloc(1);
	tmp->nb_ant = nb_ant;
	tmp->msize = 1;
	tmp->actual = -1;
	tmp->best = INT_MAX;
	tmp->scotch = nb_room;
	tmp->next = NULL;
	return (tmp);
}

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
			{
				free(tab);
				return (-1);
			}
		}
	}
	free(tab);
	return (1);
}

int		check_if_other_path(int *tab, t_end *tmp)
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

int	no_dup_v2(int test, int *path, t_slc *slc, t_end *tmp)
{
	static int	*tab = NULL;
	int	i;
	int	j;

	i = -1;
	if (check_if_other_path(tab, tmp) == 1 || tab == NULL)
	{
		tab = ft_memalloc(slc->nb_room);
		while (++i < tmp->max_len)
		{
			j = 0;
			while (++j < slc->len_path[path[i]] - 1)
				tab[slc->path[path[i]][j]] = 1;
		}
	}
	i = 0;
	while (++i < slc->len_path[test] - 1)
	{
		if (tab[slc->path[test][i]] == 1)
			return (-1);
	}
	free(tab);
	tab = NULL;
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
		if (checkndup(path, tmp, test, slc->nb_slc) == -1)
			return (-1);
		if (no_dup_v2(test, tmp->path[path], slc, tmp) == -1)
			return (-1);
		if (tmp2->nb_path + 1 == (tmp2->scotch * tmp2->msize))
			reajust_end(tmp2, tmp2->scotch);
		ft_imemcpy(tmp2->path[tmp2->nb_path], tmp->path[path], tmp->max_len);
		tmp2->path[tmp2->nb_path][tmp->max_len] = test;
		tmp2->nb_path++;
		i = 0;
		// while (i < tmp->max_len)
			// ft_printf("[%d]|", tmp->path[path][i++]);
		// ft_printf("[%d]", test);
		// ft_printf("\n");
	}
	return (1);
}

t_end	*do_the_rest(t_path *path, t_room *room, t_ant *ant)
{
	int		i_slc;
	int		j;
	t_end	*head;

	head = head_end_init(ant->nb_ant, room->nb);
	head->next = path->zend;
	path->slc->nb_room = room->nb;
	while (path->zend->nb_path != 0)
	{
		j = -1;
		path->zend->next = path_end_init(path, ant->nb_ant, room->nb);
		path->zend->next->max_len = path->zend->max_len + 1;
		while (++j < path->zend->nb_path)
		{
			i_slc = 0;
			path->zend->actual = j;
			while (i_slc < path->slc->nb_slc &&
				combinaison(path->slc, path->zend, i_slc, j) != 1)
				++i_slc;
		}
		static int i = 2;
		ft_printf("combi done : %d paths\n", ++i);
		path->zend = path->zend->next;
	}
	return (head);
}
