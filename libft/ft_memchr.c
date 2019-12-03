/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:50:33 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 18:48:56 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const int	*temp_s;
	int			a;

	a = 0;
	temp_s = (const int*)s;
	while (n != 0)
	{
		if (*(const int*)temp_s == (int)c)
			return ((void*)temp_s);
		temp_s++;
		n--;
	}
	return (NULL);
}
