/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/14 13:55:32 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:34:31 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = ft_strlen(s) + 1;
	if (s)
	{
		while (a-- != 0)
		{
			if (s[a] == c)
				return ((char*)&s[a]);
		}
	}
	return (0);
}
