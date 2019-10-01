/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_work.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/03 03:37:40 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:28 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*p_zero_flags(t_arg *arg, char *str, char *tmp, int ret)
{
	ft_memset(str, '0', arg->width);
	ft_strcpy(str + arg->width - ret + 2, tmp + 2);
	str[1] = 'x';
	return (str);
}

char	*neg_xx_scotch(t_arg *arg)
{
	char	*str;

	str = NULL;
	if (arg->type == 'x')
	{
		if (ft_strchr(arg->flags, '#'))
			str = ft_strdup("0xffffffffffffffff");
		else
			str = ft_strdup("ffffffffffffffff");
	}
	else
	{
		if (ft_strchr(arg->flags, '#'))
			str = ft_strdup("0XFFFFFFFFFFFFFFFF");
		else
			str = ft_strdup("FFFFFFFFFFFFFFFF");
	}
	return (str);
}

char	*choosestr(t_arg *arg)
{
	char	*str;

	str = NULL;
	if (arg->type == 'o')
	{
		if (ft_strequ(arg->size, "ll") || ft_strequ(arg->size, "l"))
		{
			if (ft_strchr(arg->flags, '#'))
				str = ft_strdup("01777777777777777777777");
			else
				str = ft_strdup("1777777777777777777777");
		}
		else
		{
			if (ft_strchr(arg->flags, '#'))
				str = ft_strdup("037777777777");
			else
				str = ft_strdup("037777777777");
		}
	}
	return (str);
}

char	*test(t_arg *arg, t_flags *info, va_list ap)
{
	char *tmp;

	tmp = NULL;
	if (arg->type == 's')
		if (!(tmp = s_malloc_content(arg, ap)))
			return (NULL);
	if (arg->type == 'c' || arg->type == 'p')
		if (!(tmp = c_or_p(arg, ap, info)))
			return (NULL);
	if (arg->type == 'i' || arg->type == 'd')
		if (!(tmp = di_fill_content(arg, ap, info)))
			return (NULL);
	if (arg->type == '%')
		if (!(tmp = modul_fill_content(arg, ap)))
			return (NULL);
	if (arg->type == 'x' || arg->type == 'X' || arg->type == 'o')
		if (!(tmp = xxo_fill_content(info, arg, ap)))
			return (NULL);
	if (arg->type == 'u')
		if (!(tmp = u_fill_content(info, arg, ap)))
			return (NULL);
	if (arg->type == 'f')
		if (!(tmp = f_fill_content(arg, ap)))
			return (NULL);
	return (tmp);
}
