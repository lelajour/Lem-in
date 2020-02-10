/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:56:21 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:35:05 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	if (needle[b] == '\0')
		return ((char*)haystack);
	while (haystack[a])
	{
		c = a;
		while (haystack[c] == needle[b])
		{
			if (needle[b + 1] == '\0')
				return ((char*)&haystack[a]);
			b++;
			c++;
		}
		b = 0;
		a++;
	}
	return (0);
}
