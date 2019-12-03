/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:57:36 by lelajour          #+#    #+#             */
/*   Updated: 2019/11/25 03:25:57 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lemin.h"

static t_slc	*sort_slc(t_slc *slc, int *valid_path)
{
	t_slc	*tmp;
	int		i;

	tmp = slc;
	while (tmp != NULL)
	{
		i = 0;
		if (tmp->nb_slc != 0)
		{
			*valid_path += 1;
			while (i < tmp->nb_slc - 1)
			{
				if (tmp->len_path[i] > tmp->len_path[i + 1])
				{
					swap_path(&tmp->path[i], &tmp->path[i + 1]);
					ft_swap(&tmp->len_path[i], &tmp->len_path[i + 1]);
					i = -1;
				}
				i++;
			}
		}
		tmp = tmp->next;
	}
	return (slc);
}

static int		*get_next_room(int room, t_room *r, int *i)
{
	int		*passage;
	int		len;
	int		ret;

	ret = 0;
	len = 0;
	passage = NULL;
	if (passage == NULL)
	{
		while (ret < r->nb)
		{
			if (r->link[room][ret] != 0 && r->link[room][ret] != -1)
				len++;
			ret++;
		}
		passage = init_passage(r->link[room], r->nb, len + 1);
	}
	if (passage[*i] < 0)
	{
		free(passage);
		return (NULL);
	}
	else
		return (passage);
	return (NULL);
}

void	bfs_algo(t_path *path, t_room *room, t_ant *ant, int node)
{
	int		i;
	int		*taille;

	i = 0;
	path->did[node] = 1;
	path->path[path->len_path++] = node;
	if (node == path->rend)
	{
		path_finding(path, room, ant);
		upgrade_mtc(room->link, path, room->nb);
		save_path(path, 0, room->nb);
	}
	else if ((taille = get_next_room(node, room, &i)) != NULL)
	{
		while (taille[i] != -1)
		{
			if (path->did[taille[i]] != 1)
				bfs_algo(path, room, ant, taille[i]);
			i++;
		}
		free(taille);
	}
	path->len_path--;
	path->did[node] = -1;
}

int	comp_tab(t_slc *tmp, int *tab, int *tab2, int best_i)
{
	int i = 1;
	int tabMax = 0;
	int tab2Max = 0;
	int comp = 0;
	int y = 0;

	//printf("sfssdf----> %d <-----\n", tmp->len_path[best_i]);
	printf("gggggg->%d -> %d -> %d", tab[0], tab[1], tab[2]);
	while (tab[i])
	{
		printf("\n-! ! ! %d ! ! !\n", tab[i]);
		i++;
	}
	tabMax = i;
	i = 0;
	while (i < tmp->len_path[best_i])
	{	
		printf("\n++ %d ++\n", tmp->path[best_i][i]);
		i++;
	}
	tab2Max = i;
	printf("\ntab1MAX----->%d\n", tabMax);
	printf("\ntab2MAX----->%d\n", tab2Max);
	while (y < tabMax)
	{
		if (tab[y] == tab2[y])
			comp = 1;
		y++;
	}
	return (comp);
}



t_path	*check_if_connected(t_room *room, t_ant *ant)
{
	int		pos;
	t_path	*path;
	t_slc *tmp;

	pos = 0;
	if ((path = init_path(room->link, room)) == NULL)
		return (NULL);
	path->slc = init_slc(path->nb_path);
	tmp = path->slc;
	int y = -1;
	ft_printf("La salle de départ est %d et la salle de fin est %d (rev : %d)\n", path->rstart, path->rend, path->rev);
	ft_printf("Nous sommes les salles connecté a la salle start :\n");
	while (++y < path->nb_path)
		ft_printf("[%d]|", path->to_do[y]);
	ft_printf("\n-------------\n");
	ft_printf("Nombre de paths = %d\n", path->nb_path);
	// while (tmp->nb_slc < 1 || tmp->nb_slc != -2)
	// {
		path->did[path->rstart] = 1;
		path->len_path = 0;
		bfs_algo(path, room, ant, path->rstart);
		// path->total += get_total(path->slc, pos);
		ft_printf("PATH(S) DONE : %d\n", pos + 1);
		ft_memset(path->did, -1, room->nb);
		// tmp = tmp->next;
		pos++;
	// }
	path->valid_path = 0;
	path->slc = sort_slc(path->slc, &path->valid_path);
	if (path->rev == 1)
		rev_slc(path->slc);
	tmp = path->slc;
	int x = 0;
	int k = 0;
	int j = 0;
	int minLenght = 0;
	//int best_i = 0;
	//int merde = 0;
	int **tab = malloc(sizeof(int *) * 10000);
	//int *tab2 = (int*)malloc(sizeof(int) * 10000);
	while (tmp != NULL)
	{
		int i = 0;
		ft_printf("Nous sommes les paths partant de [%d] :\n", path->to_do[x++]);
		
				while (i < tmp->nb_slc)
				{
					y = 0;
					ft_printf("%d |", i);
					while (y < tmp->len_path[i])
						ft_printf("[%d]|", tmp->path[i][y++]);
					ft_printf("%d\n", tmp->len_path[i]);
					
					y = 0;
					j = 0;
					//if (merde != 3)
					//{
						tab[i] = malloc(sizeof(int) * 10000);
						while (y < tmp->len_path[i] && (minLenght == 0 || minLenght > tmp->len_path[i]) )
						{
							
							tab[i][j] = tmp->path[i][y];
							printf("++++++ %d ++++++\n", tab[i][j]);
							j++;
							y++;
						}
						minLenght = tmp->len_path[i];
						//merde = comp_tab(tmp, tab, tmp->path[best_i], best_i);

						
					//}
					//printf("--------->   %d   <-------- \n", merde);
					
					/*y = 0;
					
					if (merde == 0 && y < tmp->len_path[i])
					{
						minLenght = tmp->len_path[i];
						while (y < tmp->len_path[i])
						{
							tab2[y] = tmp->path[i][y];
							y++;
						}
						best_i = i;
						
						merde = 3;
					}
					else if (i > 0 && ((tmp->len_path[i] < minLenght && merde == 0) || (merde == 1)))
					{
						minLenght = tmp->len_path[i];
						best_i = i;
					}*/
					i++;
				}
/*				ft_printf("\n");
				ft_printf("Chemin le plus cours: ");
				y = 0;
				while (y < tmp->len_path[best_i])
					ft_printf("[%d]|", tab2[y++]);
				ft_printf("%d\n", tmp->len_path[best_i]);
				ft_printf("\n\n\n");
*/			
		
		
		tmp = tmp->next;
		k++;
	}
	ft_printf("nb de path valide : %d\n", path->valid_path);
	return (path);
}
