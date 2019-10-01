/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnclen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 21:34:50 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 07:16:54 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnclen(char *str, char c)
{
	int	i;

	i = 0;
	if (c > 96)
		c -= 32;
	while (str[i])
	{
		if (str[i] == c || str[i] == c + 32)
			return (i);
		i++;
	}
	return (i);
}
