/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ibzero.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 13:44:35 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:35:34 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_ibzero(void *s, size_t n)
{
	int *tmp;
	int	a;

	tmp = s;
	a = 0;
	while (n-- != 0)
	{
		tmp[a++] = 0;
	}
}
