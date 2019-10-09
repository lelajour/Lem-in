/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:55:11 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:34:08 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	int a;
	int i;

	a = 0;
	i = 1;
	if (n)
	{
		while (s1[a] && (s1[a] == s2[a]) && i++ < (int)n)
			a++;
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
