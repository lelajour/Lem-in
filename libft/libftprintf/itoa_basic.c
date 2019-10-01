/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   itoa_basic.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 03:38:59 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:33 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

static char			*int_x(int x)
{
	char *str;

	str = NULL;
	if (x == 0)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	return (str);
}

char				*itoa_basic(unsigned long long value, int base, int x)
{
	int				i;
	char			*str;
	long long		tmp;
	char			*buff;

	i = 0;
	buff = int_x(x);
	tmp = value;
	while (tmp >= base || tmp <= (base * -1))
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = buff[value % base];
		value /= base;
		i--;
	}
	return (str);
}
