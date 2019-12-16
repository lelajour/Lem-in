/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:57:17 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/16 10:25:55 by lelajour         ###   ########.fr       */
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
	char						**room;
	int								pos;
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
	int		nb_room;
	int		mallocsize;
}								t_slc;

typedef struct					s_path
{
	int		rstart; //real start used by bfs
	int		rend; //real end room targeted
	int		rev; // les recherche se font a partir de la room end si egal a 1
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
	int		max_len;
	int		**path;
	int		nb_path;
	int		*heat;
	int		heat_max;
	int		*ant;
	int		msize;
	int		best;
	int		actual;
	int		lul;
	int		rappel;
	int		nb_ant;
	int		scotch;
	struct s_end	*next;
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
void						save_path(t_path *path, int nb_room);
int							look_for_end(t_room *room);
int							ft_start_chr(int **link, int nb, t_path *path);
t_slc						*init_slc(t_room *room);
void						swap_path(int **path1, int **path2);
void						do_rev(int *path, int len);
void						rev_slc(t_slc *slc);
int							set_stnd(int len_path, int nb_room);
int							ft_start_chr2(int **link, int nb);
void						upgrade_mtc(int **link, t_path *path, int nb_room);
int							*init_passage(int *link, int nb, int len);
void						path_finding(t_path *path, t_room *room, t_ant *ant);
int							is_new_path(t_path *path);
int							check_if_dup(t_path *path);
void						do_split(t_path *path);
int							look_better_path(t_path *path, int room);
int							no_dup(int p1, int p2, t_slc *slc);
t_end						*path_end_init(t_path *path, int nb_ant, int nb_room);
void						reajust_end(t_end *tmp, int nb);
t_end						*do_the_rest(t_path *path, t_room *room, t_ant *ant);
int							fill_ant(t_end *end, t_slc *slc, t_room *room);
void						affichage(t_room *room, t_end *end, t_slc *slc);
void						move_end_shit(t_end *end, int tmp);
char						**get_room_name(t_end *end, t_slc *slc, t_room *room);
void						free_shit(char **name, int **move, t_end *end);

#endif
