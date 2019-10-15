/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 12:57:17 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 10:26:14 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"
# include "limits.h"
# include "math.h"
# include "get_next_line.h"

#define DANUB 99999

typedef struct					s_room
{
	int							nb;
	int							nb_link;
	char						*name;
	int							pos;
	int							len;
	int							width;
	int							ant;
	int							error;
	int							**link;
	struct s_room		*next;
}								t_room;

typedef struct					s_ant
{
	char						*name;
	char						*room;
	char						*next_room;
	int							pos;
	unsigned int		nb_ant;
	int							error;
	struct s_ant		*next;
}								t_ant;

typedef struct					s_path
{
	int		nb_path;
	int		**path;
	int		len_did;
	int		*did;
	int		len_td;
	int		**to_do;
}								t_path;

t_ant						*ant_struct_allocation(t_ant *ant, int nb_ant);
void						ft_clear(t_ant *ant, t_room *room);
void						room_assignation(char *line);
t_room					*room_struct_allocation();
int							ft_404(t_ant *ant, t_room *room);
int							get_room_width(char *line);
int							room_check_if_double(char *line, t_room *room);
t_ant						*find_nb_ant();
t_room					*room_check(t_room *tmp, char *line);
int							**set_graph(char *line, t_room *room);
t_room					**set_room_link(char **tab, int i, int *itab, t_room *room);
char						**realloc_tab(char **tab, int i);
t_path					*init_path(int **link, t_room *room);
t_path					*heck_if_connected(t_room *room);

#endif
