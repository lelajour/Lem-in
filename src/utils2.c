/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:36:34 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/04 05:45:05 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

static int		*alloc_scotch(int len)
{
	int *passage;
	int	i;

	i = -1;
	if (!(passage = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	ft_imemset(passage, -1, len);
	return (passage);
}

void	upgrade_mtc(int **link, t_path *path, int nb_room)
{
	int	i;
	int	j;
	int	heat;

	i = path->len_path - 1;
	heat = 4;
	while (i > 0)
	{
		j = 0;
		while (j < nb_room)
		{
			if (link[path->path[i]][j] != 0 && link[path->path[i]][j] > heat)
				link[path->path[i]][j] = heat;
			j++;
		}
		heat++;
		i--;
	}
}

int		*init_passage(int *link, int nb, int len)
{
	int	*passage;
	int	ret;
	int tmp;

	ret = -1;
	tmp = 0;
	passage = alloc_scotch(len);
	while (++ret < nb)
	{
		if (link[ret] != 0 && link[ret] != -1)
			passage[tmp++] = ret;
	}
	ret = -1;
	while (++ret < len - 2)
	{
		if (link[passage[ret]] > link[passage[ret + 1]])
		{
			tmp = passage[ret];
			passage[ret] = passage[ret + 1];
			passage[ret + 1] = tmp;
			ret = -1;
		}
	}
	return (passage);
}

int		ft_start_chr2(int **link, int nb)
{
	int	j;
	int	i;
	int	start;
	int end;

	i = -1;
	start = 0;
	end = 0;
	while (++i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (link[i][j] == 1)
				start++;
			else if (link[i][j] == 3)
				end++;
			else if (link[i][j] == 2)
				break ;
			j++;
		}
	}
	if (end == 0 || start == 0)
		return (-1);
	return (0);
}
