/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_slc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 19:27:33 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 07:48:00 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

t_utils		*init_utils(t_path *path)
{
	t_utils *utils;

	utils = malloc(sizeof(t_utils) * 1);
	utils->index = 0;
	utils->nb_room = path->slc->nb_room;
	utils->did = ft_memalloc(path->slc->nb_room);
	utils->did[path->rstart] = 1;
	utils->first = NULL;
	utils->file = NULL;
	utils->count = 1;
	return (utils);
}

t_bfs		*new_fill(t_bfs *path, t_utils *u)
{
	t_bfs *tmp;

	tmp = path->next;
	u->first = path->next;
	free(path->tab);
	free(path);
	return (tmp);
}

int			check_if_limit(char *line)
{
	int		limit;
	int		i;

	limit = -1;
	i = 0;
	while (line[i])
		i++;
	if (i > 38 && ft_isdigit(line[39]) == 1)
		limit = ft_atoi(&line[39]);
	return (limit);
}

int			init_t_bfs(t_utils *u, t_path *p, int y)
{
	t_bfs *tmp;

	tmp = NULL;
	if (u->first != NULL)
	{
		while (u->first != NULL)
		{
			tmp = u->first->next;
			free(u->first->tab);
			free(u->first);
			u->first = tmp;
		}
	}
	u->file = malloc(sizeof(t_bfs) * 1);
	u->first = u->file;
	u->file->tab = ft_memalloc(2);
	u->file->len = 2;
	u->file->tab[0] = p->rstart;
	u->file->tab[1] = p->to_do[y];
	u->file->next = NULL;
	return (1);
	return (0);
}
