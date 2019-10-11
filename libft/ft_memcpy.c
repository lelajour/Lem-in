/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:50:49 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:31:59 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	unsigned int	i;

	dest_tmp = dest;
	src_tmp = src;
	i = 0;
	while (n-- != 0)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return ((void*)dest);
}
