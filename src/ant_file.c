/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_file.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/14 16:02:32 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/20 19:34:33 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/lemin.h"

static t_ant *last_ant_check(t_ant *ant, int nb)
{
	if (nb > 0 && nb <= INT_MAX)
		return (ant_struct_allocation(ant, nb));
	else
		free(ant);
	ant = NULL;
	return (ant);
}

t_ant	*find_nb_ant()
{
	char						*line;
	t_ant						*ant;
	unsigned int		nb;

	line = NULL;
	ant = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_isdigit(line[0]))
		{
			if (ft_strchr(line, ' ') || ft_strchr(line, '-'))
			{
				ft_strdel(&line);
				return (ant);
			}
			if (!(ant = malloc(sizeof(t_ant))))
				return (ant);
			nb = ft_atoi(line);
			ft_strdel(&line);
			return (last_ant_check(ant, nb));
		}
	ft_strdel(&line);
	}
	return (ant);
}

t_ant *ant_struct_allocation(t_ant *ant, int nb_ant)
{
	int		len;
	char *line;
	t_ant *tmp;

	len = 0;
	line = NULL;
	tmp = ant;
	printf("%d\n", nb_ant);
	while (++len <= nb_ant && (nb_ant > 0 && nb_ant < INT_MAX))
	{
		line = ft_itoa(len);
		ant->name = ft_strjoin("L", line);
		ant->room = NULL;
		ant->next_room = NULL;
		ant->next = NULL;
		ant->pos = 0;
		ant->nb_ant = nb_ant;
		if (len != nb_ant)
		{
			ant->next = malloc(sizeof(t_ant));
			ant = ant->next;
		}
		free(line);
	}
	return (tmp);
}
