/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:54:57 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:34:02 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	a;

	a = 0;
	str = NULL;
	if (s)
	{
		if (!(str = ft_strnew(ft_strlen((char*)s))))
			return (NULL);
		while (s[a])
		{
			str[a] = f(a, s[a]);
			a++;
		}
	}
	return (str);
}
