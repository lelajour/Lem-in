/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:55:18 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:34:12 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int a;

	a = 0;
	while (src[a] && a < (int)n)
	{
		dest[a] = src[a];
		a++;
	}
	while (a < (int)n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
