/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 14:07:37 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 00:47:38 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, unsigned int n)
{
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(dup, s, n);
	return (dup);
}
