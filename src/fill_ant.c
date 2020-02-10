/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_ant.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 12:44:55 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:07:49 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

void			recursive(int index, t_end *end, t_slc *slc, int nb_ant)
{
	int i;

	i = 0;
	while (i < end->max_len)
	{
		if (index >= slc->len_path[end->path[end->index][i]] - 1)
		{
			end->ant[i] += 1;
			nb_ant++;
		}
		if (nb_ant == end->nb_ant)
		{
			end->best = index;
			return ;
		}
		i++;
	}
	recursive(index + 1, end, slc, nb_ant);
}

void			move_end_shit(t_end *end, int tmp)
{
	int index;
	int	value;
	int	value2;

	index = tmp;
	value = end->ant[tmp];
	value2 = end->path[end->index][tmp];
	while (tmp < end->scotch - 1)
	{
		end->ant[tmp] = end->ant[tmp + 1];
		end->path[end->index][tmp] = end->path[end->index][tmp + 1];
		tmp++;
		end->ant[tmp] = value;
		end->path[end->index][tmp] = value2;
	}
	end->ant[tmp] = value;
	end->path[end->index][tmp] = value2;
}

static void		get_better_score(t_end *end, t_slc *slc)
{
	int		i;
	int		j;
	int		tmp;
	int		score;

	i = -1;
	tmp = INT_MAX;
	while (++i < end->nb_path)
	{
		j = -1;
		score = 0;
		while (++j < end->max_len)
			score += slc->len_path[end->path[i][j]];
		if (score < tmp)
		{
			tmp = score;
			end->index = i;
		}
	}
}

int				fill_ant(t_end *end, t_slc *slc, t_room *room)
{
	t_end	*tmp;
	t_end	*best;

	tmp = end;
	best = tmp;
	if (slc->min == 2)
		start_end_connectded(end, slc, room);
	else
	{
		while (tmp->nb_path != 0)
		{
			get_better_score(tmp, slc);
			recursive(0, tmp, slc, 0);
			if (best->best == 0 || tmp->best < best->best)
				best = tmp;
			tmp = tmp->next;
		}
		affichage(room, best, slc);
	}
	return (1);
}
