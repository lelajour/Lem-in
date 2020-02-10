/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:55:48 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 20:56:17 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *htack, const char *ndle, size_t n)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	if (ndle[b] == '\0')
		return ((char*)htack);
	while (htack[a])
	{
		c = a;
		while ((htack[c] == ndle[b]) && c < (int)n)
		{
			if (ndle[b + 1] == '\0')
				return ((char*)&htack[a]);
			b++;
			c++;
		}
		b = 0;
		a++;
	}
	return (NULL);
}
