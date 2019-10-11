/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:50:12 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 11:06:49 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	lenght_c(long long int c)
{
	int a;

	a = 0;
	while (c != 0)
	{
		c /= 10;
		a++;
	}
	return (a);
}

static long	lenght_c_unsigned(unsigned long long c)
{
	long a;

	a = 0;
	while (c != 0)
	{
		c /= 10;
		a++;
	}
	return (a);
}

char		*ft_itoa_unsigned(unsigned long long n)
{
	char				*nb;
	size_t				a;
	size_t				b;
	unsigned long long	i;

	a = 0;
	i = n;
	b = lenght_c_unsigned(n);
	if (!(nb = (char*)malloc(sizeof(char) * (n == 0 ? 1 : b) + 1)))
		return (NULL);
	if (i == 0)
		nb[a++] = '0';
	while ((int)a < (lenght_c_unsigned(n)))
	{
		nb[a++] = i % 10 + '0';
		i /= 10;
	}
	nb[a] = '\0';
	ft_strrev(nb);
	return (nb);
}

char		*ft_itoa(long long n)
{
	char			*nb;
	size_t			a;
	size_t			b;
	long long		i;

	a = 0;
	i = n;
	b = lenght_c(n);
	n < 0 ? b++ : b;
	if (!(nb = (char*)malloc(sizeof(char) * (n == 0 ? 1 : b) + 1)))
		return (NULL);
	if (i < 0)
		i = -i;
	if (i == 0)
		nb[a++] = '0';
	while ((int)a < (lenght_c(n)))
	{
		nb[a++] = i % 10 + '0';
		i /= 10;
	}
	if (n < 0)
		nb[a++] = '-';
	nb[a] = '\0';
	ft_strrev(nb);
	return (nb);
}
