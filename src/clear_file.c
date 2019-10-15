/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/14 17:15:22 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 16:22:30 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

int		ft_404(t_ant *ant, t_room *room)
{
	if ((room && room->error == 404) || ant == NULL)
		ft_putstr("Wrong map file\n");
	else if (room->error == 101)
		ft_putstr("2 start or end room, abording\n");
	ft_clear(ant, room);
	exit(0);
}

void	ft_clear(t_ant *ant, t_room *room)
{
	void *tmp;

	tmp = NULL;
	while (ant != NULL)
	{
		if (ant->name)
			free(ant->name);
		if (ant->room)
			free(ant->next_room);
		if (ant->next_room)
			free(ant->next->room);
		tmp = ant->next;
		free(ant);
		ant = tmp;
	}
	while (room != NULL)
	{
		if (room->name)
			free(room->name);
		if (room->link)
			free(room->link);
		tmp = room->next;
		free(room);
		room = tmp;
	}
}

static int		ft_start_chr(int *link, int nb)
{
	int	j;
	int	tmp;

	j = 0;
	tmp = 0;
	while (j < nb)
	{
		if (link[j] == 1)
			tmp++;
		else if (link[j] == 2 || link[j] == 3)
			return (-1);
		j++;
	}
	return (tmp);
}

static int		**to_do_init(int *link, t_room *room, t_path *path)
{
	int	j;
	int	ret;
	int	tmp;
	int	**to_do;

	j = 0;
	ret = 0;
	tmp = 0;
	if (!(to_do = malloc(sizeof(int*) * path->nb_path)))
		return (NULL);
	while (j < room->nb)
	{
		while (ret < path->nb_path)
			to_do[ret] = ft_imemset(ft_memalloc(room->nb), -2, room->nb);
		if (link[j] == 1)
				to_do[tmp][0] = j;
				tmp++;
		j++;
	}
	path->len_td = tmp;
	return (to_do);
}

t_path	*init_path(int **link, t_room *room)
{
	int		i;
	int		nb_path;
	t_path	*path;

	i = 0;
	if (!(path = malloc(sizeof(t_path))))
		return (NULL);
	nb_path = 0;
	while (i < room->nb)
	{
		if ((nb_path = ft_start_chr(link[i], room->nb)) != -1)
		{
			ft_printf("nb_path = %d\n", nb_path);
			path->nb_path = nb_path;
			if (!(path->path = malloc(sizeof(t_path) * nb_path)))
				return (NULL);
			while (nb_path-- > 0)
				path->path[nb_path] = ft_memalloc(room->nb);
			path->did = ft_memalloc(room->nb);
			path->did[0] = i;
			path->to_do = to_do_init(link[i], room, path);
			return (path);
		}
		i++;
	}
	return (NULL);
}
