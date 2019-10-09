/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_col.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 13:21:08 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 21:14:26 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_swap_col(char **tab, char c)
{
	char	*tmp;
	int		i;

	while (ft_strchr(tab[0], c) == NULL)
	{
		i = -1;
		while (++i < 3)
		{
			tmp = ft_strdup(tab[i]);
			ft_strcpy(tab[i], tab[i + 1]);
			ft_strcpy(tab[i + 1], tmp);
			free(tmp);
		}
		i = 0;
	}
	return (tab);
}
