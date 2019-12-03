/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:57:17 by lelajour          #+#    #+#             */
/*   Updated: 2019/11/25 01:48:10 by lelajour         ###   ########.fr       */
/*                                                                            */
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

typedef struct					s_soluce
{
	int		**path;
	int		*len_path;
	int		nb_slc;
	int		min;
	int		mallocsize;
	struct s_soluce	*next;
}								t_slc;

typedef struct					s_path
{
	int		rstart; //real start used by bfs
	int		rend; //real end room targeted
	int		rev; // les recherche se font a partir de la room de fin si egal a 1
	int		end_nb;
	int		start_nb;
	int		start;
	int		ok;
	int		end;
	int		total;
	int		nb_path;
	int		len_path;
	int		*path;
	int		*did;
	int		*to_do;
	int		valid_path;
	struct s_soluce	*slc;
	struct s_end	*zend;

}								t_path;

typedef struct					s_end
{
	int		*max_len;
	int		**path;
	int		nb_path;
	int		*heat;
	int		heat_max;
	int		*ant;
	int		nb_ant;
}								t_end;

t_ant						*ant_struct_allocation(t_ant *ant, int nb_ant);
void						ft_clear(t_ant *ant, t_room *room);
void						room_assignation(char *line);
t_room					*room_struct_allocation();
int							ft_404(t_ant *ant, t_room *room, t_path *path);
int							get_room_width(char *line);
int							room_check_if_double(char *line, t_room *room);
t_ant						*find_nb_ant();
t_room					*room_check(t_room *tmp, char *line, int *error);
int							**set_graph(char *line, t_room *room);
t_room					**set_room_link(char **tab, int i, int *itab, t_room *room);
char						**realloc_tab(char **tab, int i);
t_path					*init_path(int **link, t_room *room);
t_path					*check_if_connected(t_room *room, t_ant *ant);
int							get_to_do(t_path *path, t_room *room, int pos, int i);
void					bfs_algo(t_path *path, t_room *room, t_ant *ant, int node);
void						save_path(t_path *path, int pos, int nb_room);
int							look_for_end(t_room *room);
int							ft_start_chr(int **link, int nb, t_path *path);
t_slc						*init_slc(int nb_path);
void						swap_path(int **path1, int **path2);
void						do_rev(int *path, int len);
void						rev_slc(t_slc *slc);
int							get_total(t_slc *slc, int pos);
int							set_stnd(int len_path, int nb_room);
int							ft_start_chr2(int **link, int nb);
void						upgrade_mtc(int **link, t_path *path, int nb_room);
int							*init_passage(int *link, int nb, int len);
void							path_finding(t_path *path, t_room *room, t_ant *ant);
int							is_new_path(t_path *path);


#endif
