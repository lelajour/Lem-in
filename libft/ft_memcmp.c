/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:50:42 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:31:55 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			a;
	const char	*temp_s1;
	const char	*temp_s2;

	temp_s1 = s1;
	temp_s2 = s2;
	a = 0;
	if (n)
	{
		while (--n && (temp_s1[a] == temp_s2[a]))
			a++;
		return ((unsigned char)temp_s1[a] - (unsigned char)temp_s2[a]);
	}
	return (0);
}
