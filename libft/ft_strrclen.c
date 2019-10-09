/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrclen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 00:52:47 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 02:10:30 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrclen(char *str, char c)
{
	int	i;

	i = ft_strlen(str);
	while (i-- > 0)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
