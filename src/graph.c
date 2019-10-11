/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   graph.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 16:57:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 16:11:42 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


// ################################################
// #IL EST VRAIMENT SUPER CE LEMIN
// # EN PLUS FAIT PAR UN BG TKT SALUT
// ###############################################
// #
// #
// #

#include "../header/lemin.h"

<<<<<<< HEAD
int		check_if_double(int *tab, t_path *path, int x)
{
	if (check_loop(tab) == -1)
		return (-1);
}

t_path	*save_path(int *tab, int x)
{

}

t_path	*look_for_path(int **link, int i, int j, t_path *path)
{
	static int	*tab = NULL;
	int		x;

	x = 0;
	if (tab == NULL);
		tab = ft_imemset(ft_memalloc(room->nb), -1);
	if (tab[x] != -1)
		if ()
			tab[x] = i;
	while (++j < nb)
	{
		if (link[i][j] != 0 && link[i][j] != -1)
		{
			if (check_if_loop != 1)
				return (look_for_path(link, i, j, path));
			else
				tab[++x] = j;
			if (tab[i][j] == 3)
				path = save_path(tab, x);
			i = j;
			j = -1;
		}
	}
	return (path);
}

int		ft_end_start_chr(int *tab, , int i, int j, int nb)
{
	while (j < nb)
	{
		if ((link[i][j] != 0 || link[i][j] != -1) &&
		(link[i][j] == 1))
			return (1);
		else
			return (-1);
		j++;
	}
	return (-1);
}

t_path	*check_if_connected(t_room *room, int i)
{
	int		ret;
	int		nb_path;
	t_path	*path;

	nb_path = 0;
	ret = 0;
	path = NULL;
	while (i < room->nb)
	{
		while ((ret = ft_end_start_chr(room->link, i, ret, room->nb)) != -1)
		{
			if (look_for_path(link, i, -1, path))
				path =
			if (ret < room->nb - 1)
				ret++;
		}
		i++;
	}
	return (path);
}
=======
// char		**realloc_tab(char **tab, int i)
// {
// 	static char	**tmp;
// 	int					y;
//
// 	y = 0;
// 	tmp = ft_memalloc(i);
// 	while (y < i)
// 	{
// 		tmp[y] = ft_strdup(tab[y]);
// 		free(tab[y]);
// 		y++;
// 	}
// 	free(tab);
// 	return (tmp);
// }
//
// static t_room *take_adress(t_room *room, char *line, char *str)
// {
// 	t_room *tmp;
//
// 	tmp = room;
// 	while (tmp->next != NULL)
// 	{
// 		if (ft_strstr(line, room->name) && !ft_strstr(str, room->name))
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }
//
// static char *chearch_room_name(int i, t_room *room)
// {
// 	t_room	*tmp;
// 	char		*name;
// 	int			len;
//
// 	len = 0;
// 	tmp = room;
// 	while (len++ != i)
// 		tmp = tmp->next;
// 	name = tmp->name;
// 	return (name);
// }
//
// t_room **set_room_link(char *tab[], int i, int *itab, t_room *room)
// {
// 	t_room	**link;
// 	char		*str;
// 	int			y;
// 	int			x;
//
// 	y = 0;
// 	x = 0;
// 	char *svp;
// 	str = chearch_room_name(i, room);
// 	if (!(link = (t_room**)malloc(sizeof(t_room*) * itab[i])))
// 		exit(1);
// 	while (y < room->nb_link)
// 	{
// 		if ((svp = ft_strstr(str, tab[y])))
// 			if ((link[x++] = take_adress(room, tab[y], str)) == NULL)
// 				exit(1);
// 		ft_printf("[%p][%d][%s]--[%s]\n", &link[x], x, tab[y], svp);
// 		y++;
// 	}
// 	return (link);
// }
>>>>>>> a1b48a609145c9e60f54af4b22584df759e634d8
