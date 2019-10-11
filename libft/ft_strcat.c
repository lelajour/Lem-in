/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:52:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 17:55:51 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (dest[i])
		i++;
	while (src[b])
	{
		dest[i + b] = src[b];
		b++;
	}
	dest[i + b] = '\0';
	return (dest);
}
