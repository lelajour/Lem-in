/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:55:39 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:34:21 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	a;

	a = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}
