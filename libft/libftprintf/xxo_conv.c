/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xxo_conv.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 22:17:11 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:59 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*hashtag_flags(int i, char *tmp, t_arg *arg)
{
	char	*str;

	if (*tmp != '0')
	{
		if (i == 1 || i == 2)
		{
			str = ft_strnew(ft_strlen(tmp) + 2);
			ft_strcpy(str + 2, tmp);
			*str = '0';
			*(str + 1) = arg->type;
		}
		else
		{
			str = ft_strnew(ft_strlen(tmp) + 1);
			ft_strcpy(str + 1, tmp);
			*str = '0';
		}
		free(tmp);
		return (str);
	}
	return (tmp);
}

char	*choose_ur_tmp(t_arg *arg, long long i)
{
	char	*str;
	char	*tmp;
	int		ret;

	if (arg->type == 'x')
		str = itoa_basic(i, 16, 0);
	else if (arg->type == 'X')
		str = itoa_basic(i, 16, 1);
	else
		str = itoa_basic(i, 8, 0);
	ret = ft_strlen(str);
	if (*str != '0' && ft_strchr(arg->flags, '#') && arg->preci < ret && i > 0)
	{
		if (!ft_strchr(arg->flags, '-'))
			if (arg->width > ret && ft_strchr(arg->flags, '0'))
				return (str);
		if (arg->type == 'x')
			tmp = hashtag_flags(1, str, arg);
		else if (arg->type == 'X')
			tmp = hashtag_flags(2, str, arg);
		else
			tmp = hashtag_flags(3, str, arg);
		return (tmp);
	}
	return (str);
}

char	*xxo_flags(va_list ap, t_arg *arg, t_flags *info)
{
	char			*tmp;
	long long		ret;

	ret = 0;
	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	if (arg->preci == -1)
		arg->preci = va_arg(ap, int);
	if (*arg->size != '\0')
	{
		while (ft_strcmp(arg->size, info->flags[ret]))
			ret++;
		if (ret == 0)
			ret = 4;
	}
	if (ret == 0 || ret == 3 || ret == 1)
		ret = va_arg(ap, unsigned int);
	else if (ret == 2)
		ret = va_arg(ap, unsigned long);
	else if (ret == 4 || ret == 2)
		ret = va_arg(ap, unsigned long long);
	tmp = choose_ur_tmp(arg, ret);
	if (ret < 0)
		tmp = neg_value_xxo(tmp, arg);
	return (tmp);
}

char	*neg_value_xxo(char *tmp, t_arg *arg)
{
	char	*str;
	int		i;
	int		len;

	i = ft_strlen(tmp);
	if (arg->type == 'x' || arg->type == 'X')
		str = neg_xx(tmp, arg, i);
	else
	{
		str = choosestr(arg);
		len = ft_strlen(str);
		ft_strcpy(str + len - i, tmp);
	}
	free(tmp);
	return (str);
}

char	*xxo_fill_content(t_flags *info, t_arg *arg, va_list ap)
{
	char	*tmp;
	int		ret;
	char	*oups;

	tmp = xxo_flags(ap, arg, info);
	ret = ft_strlen(tmp);
	if (*tmp == '0' && arg->preci == 0)
	{
		oups = tmp;
		if (arg->type == 'o' && ft_strchr(arg->flags, '#'))
			tmp = ft_strdup("0");
		else
			tmp = ft_strdup("");
		free(oups);
	}
	if (arg->preci >= ret)
		tmp = xxo_preci_malloc(arg, tmp, ret);
	ret = ft_strlen(tmp);
	if (arg->width > ret)
		tmp = xxo_width_malloc(arg, tmp, ret);
	return (tmp);
}
