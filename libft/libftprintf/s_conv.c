/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   s_conv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 09:19:00 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:49 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*s_malloc_content(t_arg *arg, va_list ap)
{
	char	*buff;
	char	*tmp;
	int		ret;

	tmp = NULL;
	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	if (arg->preci == -1)
		arg->preci = va_arg(ap, int);
	tmp = s_fill_content(arg, ap);
	ret = ft_strlen(tmp);
	if (arg->width > ret)
	{
		buff = ft_memset(ft_strnew(arg->width), ' ', arg->width);
		if (ft_strchr(arg->flags, '-'))
			ft_strcpy(buff, tmp);
		else if (ft_strchr(arg->flags, '0'))
			ft_strcpy(ft_memset(buff, '0', arg->width) + arg->width - ret, tmp);
		else
			ft_strcpy(buff + arg->width - ret, tmp);
	}
	else
		buff = ft_strdup(tmp);
	free(tmp);
	return (buff);
}

char	*s_fill_content(t_arg *arg, va_list ap)
{
	char	*str;
	char	*tmp;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (arg->preci < ft_strlen(str) && arg->preci != -2)
		tmp = ft_strndup(str, arg->preci);
	else
		tmp = ft_strdup(str);
	if (*str == '(')
		free(str);
	return (tmp);
}
