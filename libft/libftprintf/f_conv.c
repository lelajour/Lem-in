/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_conv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/21 14:47:56 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:23 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

static char		*plus_flags(char *str, t_arg *arg)
{
	char *tmp;

	tmp = NULL;
	if (*str != '-' && ft_strchr(arg->flags, '+'))
	{
		tmp = ft_strnew(ft_strlen(str) + 1);
		ft_strcpy(tmp + 1, str);
		*tmp = '+';
		free(str);
		return (tmp);
	}
	else if (ft_strchr(arg->flags, ' ') && *str != '-')
	{
		tmp = ft_strnew(ft_strlen(str) + 1);
		ft_strcpy(tmp + 1, str);
		*tmp = ' ';
		free(str);
		return (tmp);
	}
	return (str);
}

static char		*f_flags(va_list ap, t_arg *arg)
{
	char			*tmp;
	long double		i;
	int				ret;

	ret = 0;
	i = 0;
	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	if (arg->preci == -1)
		arg->preci = va_arg(ap, int);
	if (*arg->size != '\0')
		ret++;
	if (ret == 1)
		i = va_arg(ap, long double);
	else
		i = va_arg(ap, double);
	tmp = f_toa(i, arg->preci);
	if (ft_strchr(arg->flags, '+') || ft_strchr(arg->flags, ' '))
		tmp = plus_flags(tmp, arg);
	return (tmp);
}

char			*plus_flags_width(char *buff, char *tmp, int ret)
{
	ft_strcpy(buff + ft_strlen(buff) - ret + 1, tmp + 1);
	*buff = *tmp;
	return (buff);
}

char			*f_fill_content(t_arg *arg, va_list ap)
{
	char	*str;
	int		ret;
	char	*buff;

	str = f_flags(ap, arg);
	ret = ft_strlen(str);
	if (arg->width > ret)
	{
		buff = ft_memset(ft_strnew(arg->width), ' ', arg->width);
		if (ft_strchr(arg->flags, '-'))
			ft_strcpy(buff, str);
		else if (ft_strchr(arg->flags, '0'))
		{
			buff = ft_memset(buff, '0', arg->width);
			if (ft_strchr(arg->flags, '+'))
				buff = plus_flags_width(buff, str, ret);
			else
				ft_strcpy(buff + arg->width - ret, str);
		}
		else
			ft_strcpy(buff + arg->width - ret, str);
		free(str);
		return (buff);
	}
	return (str);
}
