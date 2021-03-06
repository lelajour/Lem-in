/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:15:22 by lelajour          #+#    #+#             */
/*   Updated: 2020/02/02 20:10:12 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/lemin.h"

static void		clear_zend(t_end *zend, int nb_room)
{
	t_end	*tmp;

	while (zend != NULL)
	{
		if (zend->heat != NULL)
			free(zend->heat);
		if (zend->ant != NULL)
			free(zend->ant);
		if (zend->path != NULL)
			ft_clear_int_tab(zend->path, (nb_room * zend->msize));
		tmp = zend->next;
		free(zend);
		zend = tmp;
	}
}

static void		clear_utils(t_utils *u)
{
	t_bfs	*tmp;

	tmp = NULL;
	while (u->first != NULL)
	{
		tmp = u->first;
		if (u->first->tab != NULL)
			free(u->first->tab);
		u->first = u->first->next;
		free(tmp);
		tmp = NULL;
	}
	free(u->did);
	u->did = NULL;
	free(u);
	u = NULL;
}

static void		ft_clear_path(t_path *path, int nb_room)
{
	if (path->to_do != NULL)
		free(path->to_do);
	if (path->did != NULL)
		free(path->did);
	if (path->path != NULL)
		free(path->path);
	if (path->zend != NULL)
		clear_zend(path->zend, nb_room);
	if (path->utils != NULL)
		clear_utils(path->utils);
	if (path->slc != NULL)
	{
		if (path->slc->path != NULL)
			ft_clear_int_tab(path->slc->path, path->slc->nb_slc);
		if (path->slc->len_path != NULL)
			free(path->slc->len_path);
		if (path->slc->sum != NULL)
			free(path->slc->sum);
		if (path->slc->did != NULL)
			free(path->slc->did);
		free(path->slc);
	}
	free(path);
}

int				ft_404(t_ant *ant, t_room *room, t_path *path, int error)
{
	int	nb_room;

	nb_room = room->nb;
	if (error == 1)
		room->error = 404;
	if ((room && room->error == 404) || ant == NULL)
		ft_putstr("Wrong map file\n");
	else if (room->error == 101)
		ft_putstr("2 start or end room, abording\n");
	else if (path && path->valid_path == 0)
		ft_putstr("No valid path, abording\n");
	ft_clear(ant, room);
	if (path != NULL)
		ft_clear_path(path, nb_room);
	exit(0);
}

void			ft_clear(t_ant *ant, t_room *room)
{
	void	*tmp;

	tmp = NULL;
	while (ant != NULL)
	{
		if (ant->name)
			free(ant->name);
		if (ant->room)
			free(ant->room);
		tmp = ant->next;
		free(ant);
		ant = tmp;
	}
	while (room != NULL)
	{
		if (room->name)
			free(room->name);
		if (room->link)
			ft_clear_int_tab(room->link, room->nb);
		tmp = room->next;
		free(room);
		room = tmp;
	}
}
