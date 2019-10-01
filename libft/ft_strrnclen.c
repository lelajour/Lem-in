/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrnclen.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 21:35:54 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 07:17:12 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrnclen(char *str, char c)
{
	int	i;

	if (c > 96)
		c -= 32;
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == c || str[i] == c + 32)
			return (i);
		i--;
	}
	return (i);
}
