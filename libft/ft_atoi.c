/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:48:03 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:30:38 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	a;
	int	pos;
	int	nb;

	a = 0;
	pos = 1;
	nb = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
		if (str[a++] == '-')
			pos = -1;
	while (str[a] && (str[a] >= '0' && str[a] <= '9'))
		nb = (nb * 10) + (str[a++] - '0');
	return ((int)nb * (int)pos);
}
