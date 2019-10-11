/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 18:06:36 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:35:09 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;

	a = 0;
	str = NULL;
	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (s[start] && len--)
		{
			str[a++] = s[start++];
		}
	}
	return (str);
}
