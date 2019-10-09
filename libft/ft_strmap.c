/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:54:50 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:33:59 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f) (char))
{
	char	*str;
	size_t	a;

	a = 0;
	str = NULL;
	if (s)
	{
		if (!(str = ft_strnew(ft_strlen((char*)s))))
			return (NULL);
		while (s[a])
		{
			str[a] = f(s[a]);
			a++;
		}
	}
	return (str);
}
