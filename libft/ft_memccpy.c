/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:50:27 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:02:17 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*dest_tmp;
	const unsigned char		*src_tmp;
	unsigned int			i;

	dest_tmp = (unsigned char*)dest;
	src_tmp = (const unsigned char*)src;
	i = 0;
	while (n-- != 0)
	{
		dest_tmp[i] = src_tmp[i];
		if (dest_tmp[i] == (unsigned char)c)
			return ((unsigned char*)&dest[i + 1]);
		i++;
	}
	return (NULL);
}
