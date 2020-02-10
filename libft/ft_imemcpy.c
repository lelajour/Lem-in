/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_imemcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 07:31:27 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:35:42 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_imemcpy(void *dest, void *src, size_t n)
{
	unsigned int	*dest_tmp;
	unsigned int	*src_tmp;
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
