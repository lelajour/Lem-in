/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modulo_conv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 14:51:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:07 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*modul_fill_content(t_arg *arg, va_list ap)
{
	char	*c;
	int		i;

	i = 0;
	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	if (arg->width != -2)
	{
		c = ft_memset(ft_strnew(arg->width), ' ', arg->width);
		if (ft_strchr(arg->flags, '-'))
			c[i] = '%';
		else if (ft_strchr(arg->flags, '0'))
		{
			c = ft_memset(c, '0', arg->width);
			c[arg->width - 1] = '%';
		}
		else
			c[arg->width - 1] = '%';
	}
	else
		c = ft_strdup("%");
	return (c);
}
