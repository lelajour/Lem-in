/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c_conv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 11:48:54 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:10 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*c_or_p(t_arg *arg, va_list ap, t_flags *info)
{
	int i;

	i = 0;
	if (arg->type != 'c')
		i = 1;
	if (i == 0)
		return (c_fill_content(arg, ap, info));
	else if (i == 1)
		return (p_fill_content(arg, ap));
	return (NULL);
}

char	*p_va_arg(t_arg *arg, va_list ap)
{
	unsigned long		ret;
	char				*str;
	char				*tmp;

	(void)arg;
	ret = va_arg(ap, unsigned long);
	tmp = ft_itoa_base(ret, 16, 0);
	if (ret == 0 && arg->preci != 0)
		str = ft_strdup("0x0");
	else if (arg->preci == 0 && ret == 0)
		str = ft_strdup("0x");
	else
		str = ft_strjoin("0x", tmp);
	free(tmp);
	return (str);
}

char	*p_fill_content(t_arg *arg, va_list ap)
{
	char	*tmp;
	char	*str;
	int		ret;

	str = NULL;
	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	if (arg->preci == -1)
		arg->width = va_arg(ap, int);
	tmp = p_va_arg(arg, ap);
	ret = ft_strlen(tmp);
	if (arg->width > ret)
	{
		str = ft_memset(ft_strnew(arg->width), ' ', arg->width);
		if (ft_strchr(arg->flags, '-'))
			ft_strcpy(str, tmp);
		else if (ft_strchr(arg->flags, '0'))
			str = p_zero_flags(arg, str, tmp, ret);
		else
			ft_strcpy(str + arg->width - ret, tmp);
		free(tmp);
		return (str);
	}
	return (tmp);
}

char	*c_fill_content(t_arg *arg, va_list ap, t_flags *info)
{
	char	*c;
	int		i;

	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	i = va_arg(ap, int);
	if (i == 0)
		arg->c_i = 1;
	else
		arg->c_i = 0;
	if (arg->width != -2)
		c = c_width_malloc(i, arg);
	else
		c = ft_memset(ft_strnew(1), i, 1);
	if (i == '\0')
		info->len_arg += 1;
	return (c);
}

char	*c_width_malloc(int c, t_arg *arg)
{
	char	*str;

	if (c == 0 && !ft_strchr(arg->flags, '-'))
		str = ft_memset(ft_strnew(arg->width), ' ', arg->width);
	else
		str = ft_memset(ft_strnew(arg->width), ' ', arg->width);
	str[arg->width] = '\0';
	if (ft_strchr(arg->flags, '-') && c != '\0')
		str[0] = c;
	else if (ft_strchr(arg->flags, '0'))
	{
		ft_memset(str, '0', arg->width);
		str[arg->width - 1] = c;
	}
	else
		str[arg->width - 1] = c;
	return (str);
}
