/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:53:49 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 21:26:02 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*tab;
	int		a;

	a = 0;
	tab = NULL;
	if (str)
	{
		while (str[a])
			a++;
		if (!(tab = (char*)malloc(sizeof(char) * (a) + 1)))
			return (NULL);
		if (tab == NULL)
			return (NULL);
		a = 0;
		while (str[a])
		{
			tab[a] = str[a];
			a++;
		}
		tab[a] = '\0';
	}
	return (tab);
}
