/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_toa.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/21 15:31:27 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:31 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_arrondi(char *str, int ret)
{
	char	c;

	c = str[ret];
	if (c >= '5' && c < '9')
	{
		c = str[ret - 1];
		str[ret - 1] = ++c;
	}
	str[ret] = '\0';
	return (str);
}

static char	*fill_str(unsigned long integer, unsigned long decimal, int ret)
{
	int		i;
	char	*str;
	char	*inte;
	char	*dec;

	inte = ft_itoa(integer);
	dec = ft_itoa(decimal);
	i = ft_strlen(inte) + ft_strlen(dec);
	ret += ft_strlen(inte);
	str = ft_memset(ft_strnew(i + 1), '\0', i + 1);
	ft_strcpy(str, inte);
	if (decimal > 0)
	{
		str[ft_strlen(inte)] = '.';
		ft_strcpy(&str[ft_strlen(inte) + 1], dec);
	}
	free(dec);
	free(inte);
	str = ft_arrondi(str, ret);
	return (str);
}

char		*zero_arrondi(char *str)
{
	int		i;
	char	c;

	i = ft_strlen(str) - 1;
	c = str[i];
	if (str[i] == '9')
	{
		c = str[i - 1];
		str[i] = '0';
		str[i - 1] = ++c;
	}
	else
		str[i] = ++c;
	return (str);
}

char		*me_zero(long double nb)
{
	long	inte;
	long	deci;
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	inte = (long)nb;
	deci = (nb - (long)nb) * 10000;
	str = ft_itoa(inte);
	tmp = ft_itoa(deci);
	if (*tmp == '-')
		i++;
	if (tmp[i] >= '5')
		str = zero_arrondi(str);
	free(tmp);
	return (str);
}

char		*f_toa(long double nb, int preci)
{
	unsigned long long	i;
	long				integer;
	long				decimal;
	char				*str;
	int					ret;

	ret = 7;
	if (preci == 0)
		return (me_zero(nb));
	if (preci != -2)
		ret = preci + 1;
	if (preci >= 7)
	{
		i = 10;
		while (preci-- > 0)
			i *= 10;
	}
	else
		i = 10000000;
	integer = (long)nb;
	decimal = (nb - (long)nb) * i;
	if (decimal < 0)
		decimal *= -1;
	str = fill_str(integer, decimal, ret);
	return (str);
}
