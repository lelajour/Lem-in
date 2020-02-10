/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:57:17 by lelajour          #+#    #+#             */
/*   Updated: 2020/02/02 20:09:41 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"
# include "limits.h"
# include "math.h"
# include "get_next_line.h"

typedef struct					s_room
{
	int							nb;
	int							nb_link;
	char						*name;
	int							pos;
	int							connex;
	int							big;
	int							len;
	int							nb_sec;
	int							width;
	int							ant;
	int							limit;
	int							comb;
	int							error;
	int							**link;
	struct s_room				*next;
}								t_room;

typedef struct					s_ant
{
	char						*name;
	char						**room;
	int							pos;
	unsigned int				nb_ant;
	int							error;
	struct s_ant				*next;
}								t_ant;

typedef struct					s_soluce
{
	int							**path;
	int							*len_path;
	int							nb_slc;
	int							min;
	int							nb_room;
	int							*sum;
	int							*did;
	int							ldid;
	int							best;
	int							button;
	int							mallocsize;
}								t_slc;

typedef struct					s_bfs
{
	int							*tab;
	int							len;
	struct s_bfs				*next;

}								t_bfs;

typedef struct					s_utils
{
	int							index;
	int							count;
	int							nb_room;
	int							*did;
	struct s_bfs				*first;
	struct s_bfs				*file;
}								t_utils;

typedef struct					s_path
{
	int							rstart;
	int							rend;
	int							rev;
	int							end_nb;
	int							start_nb;
	int							start;
	int							end;
	int							ok;
	int							lentd;
	int							total;
	int							nb_path;
	int							limit;
	int							len_path;
	int							*path;
	int							*did;
	int							*to_do;
	int							valid_path;
	struct s_soluce				*slc;
	struct s_end				*zend;
	struct s_utils				*utils;
}								t_path;

typedef struct					s_end
{
	int							max_len;
	int							**path;
	int							nb_path;
	int							*heat;
	int							heat_max;
	int							*ant;
	int							msize;
	int							best;
	int							d;
	int							index;
	int							actual;
	int							lul;
	int							rappel;
	int							nb_ant;
	int							scotch;
	struct s_end				*next;
}								t_end;

t_ant							*ant_struct_allocation(t_ant *ant, int nb_ant);
void							ft_clear(t_ant *ant, t_room *room);
void							room_assignation(char *line);
t_room							*room_struct_allocation();
int								ft_404(t_ant *ant, t_room *room, t_path *path,
		int error);
int								get_room_width(char *line);
int								room_check_if_double(char *line, t_room *room);
t_ant							*find_nb_ant();
t_room							*room_check(t_room *tmp,
		char *line, int *error);
int								**set_graph(char *line, t_room *room);
t_room							**set_room_link(char **tab, int i,
		int *itab, t_room *room);
char							**realloc_tab(char **tab, int i);
t_path							*init_path(int **link, t_room *room);
t_path							*check_if_connected(t_room *room, t_ant *ant);
int								get_to_do(t_path *path,
		t_room *room, int pos, int i);
void							bfs_algo(t_path *path,
		t_room *room, t_ant *ant);
void							save_path(t_path *path, int nb_room, int *p);
int								look_for_end(t_room *room);
int								ft_start_chr(int **link, int nb, t_path *path);
t_slc							*init_slc(t_room *room, t_path *path);
void							swap_path(int **path1, int **path2);
void							do_rev(int *path, int len);
void							rev_slc(t_slc *slc);
int								set_stnd(int len_path, int nb_room);
int								ft_start_chr2(int **link, int nb);
void							upgrade_mtc(int **link,
		t_path *path, int nb_room);
int								*init_passage(int *link, int nb, int len);
void							path_finding(t_path *path,
		t_room *room, t_ant *ant);
int								is_new_path(t_path *path);
int								check_if_dup(t_path *path);
void							do_split(t_path *path);
int								look_better_path(t_path *path, int room);
int								no_dup(int p1, int p2, t_slc *slc);
t_end							*path_end_init(t_path *path,
		int nb_ant, int nb_room);
void							reajust_end(t_end *tmp, int nb);
t_end							*do_the_rest(t_path *path,
		t_room *room, t_ant *ant);
int								fill_ant(t_end *end, t_slc *slc, t_room *room);
void							affichage(t_room *room,
		t_end *end, t_slc *slc);
void							move_end_shit(t_end *end, int tmp);
char							**get_room_name(t_end *end,
		t_slc *slc, t_room *room);
void							free_shit(char **name, int **move, t_end *end);
void							del_dead_end(int **matrice, int nb);
int								still_good(t_path *path);
void							count_per_path(t_path *path);
int								not_repetitive(t_slc *slc, t_path *path);
t_utils							*init_utils();
int								path_check(t_path *path);
void							realloc_in_q(t_utils *u);
t_bfs							*new_fill(t_bfs *path, t_utils *u);
int								check_if_limit(char *line);
int								init_t_bfs(t_utils *u, t_path *p, int y);
t_bfs							*add_path(int node, t_path *p);
int								check_if_here(int *path, int tmp, int len);
int								check_if_other_path(int *tab, t_end *tmp);
int								*copy_path(t_path *path, int node);
void							start_end_connectded(t_end *end,
		t_slc *slc, t_room *room);
int								sctochhisimo(t_room *room);
int								combi_soctch(t_path *path, t_room *room, int j);

#endif
