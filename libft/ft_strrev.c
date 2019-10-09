/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:56:02 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:34:34 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	b = 0;
	while (str[a])
		a++;
	a--;
	while (b < a)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		a--;
		b++;
	}
	return (str);
}
