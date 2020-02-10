/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:53:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:32:42 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int a;
	int i;

	a = 0;
	if (!(unsigned char)c)
	{
		i = ft_strlen(s);
		if (s[i] == (unsigned char)c)
			return ((char*)&s[i]);
	}
	while (s[a])
	{
		if (s[a] == (unsigned char)c)
			return ((char*)&s[a]);
		a++;
	}
	return (0);
}
