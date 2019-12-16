/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:44:55 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/14 17:59:27 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

void	recursive(int index, t_end *end, t_slc *slc, int nb_ant)
{
	int i;

	i = 0;
	while (i < end->max_len)
	{
		if (index >= slc->len_path[end->path[0][i]] - 1)
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

void	move_end_shit(t_end *end, int tmp)
{
	int index;
	int	value;
	int	value2;

	index = tmp;
	value = end->ant[tmp];
	value2 = end->path[0][tmp];
	while (tmp < end->scotch - 1)
	{
		end->ant[tmp] = end->ant[tmp + 1];
		end->path[0][tmp] = end->path[0][tmp + 1];
		tmp++;
		end->ant[tmp] = value;
		end->path[0][tmp] = value2;
	}
	end->ant[tmp] = value;
	end->path[0][tmp] = value2;
}

int		fill_ant(t_end *end, t_slc *slc, t_room *room)
{
	t_end *tmp;
	t_end *best;
	int	i;

	tmp = end;
	best = tmp;
	while (tmp->nb_path != 0)
	{
		i = 0;
		recursive(0, tmp, slc, 0);
		if (best->best == 0 || tmp->best < best->best)
			best = tmp;
		ft_printf("\n\n---------\n");
		ft_printf("je suis le nombre de tour des combinais a %d paths : %d\n", tmp->max_len, tmp->best);
		while (i < tmp->max_len)
			ft_printf("%d|", tmp->ant[i++]);
		ft_printf("\n");
		tmp = tmp->next;
	}
 	affichage(room, best, slc);
	return (1);
}
