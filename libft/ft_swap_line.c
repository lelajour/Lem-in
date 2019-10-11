/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 13:20:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 13:41:22 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				**ft_swap_line(char **tab)
{
	int		i;
	int		j;
	char	tmp;

	while (ft_colchr(tab, '#') == NULL)
	{
		i = -1;
		while (++i < 4)
		{
			j = 0;
			while (j < 3)
			{
				tmp = tab[i][j];
				tab[i][j] = tab[i][j + 1];
				tab[i][j + 1] = tmp;
				j++;
			}
		}
	}
	return (tab);
}
