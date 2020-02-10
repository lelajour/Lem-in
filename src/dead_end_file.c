/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dead_end_file.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 17:26:31 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 04:33:36 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

int				not_repetitive(t_slc *slc, t_path *path)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (slc->button != path->path[1])
	{
		while (++i < slc->nb_room)
			slc->did[i] = 0;
		slc->button = path->path[1];
	}
	i = -1;
	while (++i < path->len_path)
	{
		if (path->len_path > slc->did[path->path[i]])
		{
			count++;
			slc->did[path->path[i]] = path->len_path;
		}
	}
	return (count >= 1 ? 1 : -1);
}

int				still_good(t_path *path)
{
	int		i;

	i = -1;
	while (path->len_path > 2 && ++i < path->nb_path)
	{
		if (path->path[1] == path->to_do[i])
		{
			if (path->slc->sum[i] < 800 / path->nb_path)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

void			count_per_path(t_path *path)
{
	int		i;

	i = -1;
	while (++i < path->nb_path)
	{
		if (path->path[1] == path->to_do[i])
			break ;
	}
	path->slc->sum[i] += 1;
}

static void		actualy_del_something(int **matrice, int nb, int *link)
{
	int	i;
	int j;

	i = -1;
	while (++i < nb)
	{
		if (link[i] == 1)
		{
			j = -1;
			while (++j < nb)
			{
				if (matrice[i][j] > 3)
				{
					matrice[i][j] = 0;
					matrice[j][i] = 0;
					link[i] -= 1;
					link[j] -= 1;
					actualy_del_something(matrice, nb, link);
				}
			}
		}
	}
}

void			del_dead_end(int **matrice, int nb)
{
	int		*link;
	int		i;
	int		j;

	link = ft_memalloc(nb);
	i = -1;
	while (++i < nb)
	{
		j = -1;
		while (++j < nb)
		{
			if (matrice[i][j] == 1 || matrice[i][j] == 3)
			{
				link[i] = -1;
				break ;
			}
			else if (matrice[i][j] > 3)
				link[i] += 1;
		}
	}
	actualy_del_something(matrice, nb, link);
	free(link);
}
