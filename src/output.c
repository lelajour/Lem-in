/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:32:06 by lelajour          #+#    #+#             */
/*   Updated: 2020/02/02 19:40:23 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/lemin.h"

static int	adjust_maxlen(t_end *end)
{
	int i;

	i = 0;
	while (i < end->max_len)
	{
		if (end->ant[i] == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	get_path_tmp(t_end *end, int rturn)
{
	static int	i = 0;
	static int	turn = 0;
	int			ret;
	int			tmp;

	if (rturn == turn + 1)
	{
		turn += 1;
		i = 0;
	}
	tmp = i % end->max_len;
	ret = end->path[end->index][tmp];
	end->ant[tmp] -= 1;
	if (end->ant[i % end->max_len] == 0)
	{
		move_end_shit(end, tmp);
		end->scotch--;
		return (ret);
	}
	i++;
	return (ret);
}

int			get_turn(t_end *end)
{
	static int i = 0;

	i++;
	if (i / end->max_len == 1)
	{
		i = 0;
		return (1);
	}
	else
		return (0);
}

static int	**list_ant_fill(t_end *end, t_slc *s)
{
	int		**path;
	int		ant;
	int		turn;
	int		tmp;

	ant = -1;
	turn = 0;
	end->scotch = end->max_len;
	path = malloc(sizeof(int**) * end->nb_ant);
	while (++ant < end->nb_ant)
	{
		end->lul = turn;
		path[ant] = ft_imemset(ft_memalloc(end->best), -1, end->best);
		tmp = get_path_tmp(end, turn);
		ft_imemcpy(path[ant] + turn, s->path[tmp] + 1, s->len_path[tmp] - 1);
		turn += get_turn(end);
		if (turn > end->lul)
			end->max_len = end->scotch;
	}
	return (path);
}

void		affichage(t_room *room, t_end *end, t_slc *slc)
{
	int		i;
	int		j;
	int		**move;
	char	**name;

	if (ft_memchr(end->ant, 0, end->max_len) != NULL)
		end->max_len = adjust_maxlen(end);
	end->rappel = end->max_len;
	move = list_ant_fill(end, slc);
	name = get_room_name(end, slc, room);
	j = 0;
	while (j < end->best)
	{
		i = 0;
		while (i < end->nb_ant)
		{
			if (move[i][j] != -1)
				ft_printf("L%d-%s ", i + 1, name[move[i][j]]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	ft_printf("\n\nNUMBER OF LINE : %d\n", end->best);
	free_shit(name, move, end);
}
