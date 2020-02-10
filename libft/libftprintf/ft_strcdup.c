/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcdup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/16 21:06:12 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 15:12:42 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcdup(char *str, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	tmp = ft_strncpy(ft_strnew(i), str, i);
	return (tmp);
}
