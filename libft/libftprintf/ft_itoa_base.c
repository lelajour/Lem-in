/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 20:13:48 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 04:24:44 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	conv_ex(int nb, int x)
{
	if (nb >= 10 && x == 0)
		return (nb - 10 + 'a');
	else if (nb >= 10 && x == 1)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

char		*ft_itoa_base(unsigned long long value, int base, int x)
{
	long				i;
	char				*str;
	long				tmp;

	i = 0;
	tmp = value;
	while ((long)tmp >= base || tmp < 0)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp, x);
		value /= base;
		i--;
	}
	return (str);
}
