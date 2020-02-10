/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_finder_utlils.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 23:56:23 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:33:01 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

t_end	*head_end_init(int nb_ant, int nb_room)
{
	t_end	*tmp;
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
	tmp->d = 0;
	tmp->index = 0;
	tmp->best = INT_MAX;
	tmp->scotch = nb_room;
	tmp->next = NULL;
	return (tmp);
}

int		checkndup(int path, t_end *end, int test, int nb)
{
	int	*tab;
	int	i;
	int	j;
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
		j = end->next->max_len;
		count = 0;
		while (--j > 0)
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

int		no_dup_v2(int test, int *path, t_slc *slc, t_end *tmp)
{
	static int	*tab = NULL;
	int			i;
	int			j;

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
	i = slc->len_path[test] - 1;
	while (--i > 0)
	{
		if (tab[slc->path[test][i]] == 1)
			return (-1);
	}
	free(tab);
	tab = NULL;
	return (1);
}

int		comb(t_slc *slc, t_end *tmp, int test, int path)
{
	int		i;
	t_end	*tmp2;

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
	}
	return (1);
}

t_end	*do_the_rest(t_path *p, t_room *r, t_ant *ant)
{
	int		i;
	int		j;
	t_end	*head;

	head = head_end_init(ant->nb_ant, r->nb);
	head->next = p->zend;
	p->slc->nb_room = r->nb;
	while (p->zend->nb_path != 0)
	{
		j = -1;
		p->zend->next = path_end_init(p, ant->nb_ant, r->nb);
		p->zend->next->max_len = p->zend->max_len + 1;
		p->zend->d = p->zend->nb_path > 100 ? p->zend->nb_path * 0.10 : 0;
		while (++j < (p->zend->nb_path - p->zend->d) && p->zend->max_len < 15)
		{
			i = 0;
			p->zend->actual = j;
			while (i < p->slc->nb_slc && comb(p->slc, p->zend, i, j) != 1)
				++i;
			if (r->nb_sec++ == 5 && r->big == 1 && sctochhisimo(r) == 1)
				break ;
		}
		p->zend = p->zend->next;
	}
	return (head);
}
