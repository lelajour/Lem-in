/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   u_conv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/06 17:03:21 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:52 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*u_flags(va_list ap, t_arg *arg, t_flags *info)
{
	char					*tmp;
	unsigned long			i;
	int						ret;

	ret = 2;
	i = 0;
	if (arg->width == -1)
		arg->width = va_arg(ap, int);
	if (arg->preci == -1)
		arg->preci = va_arg(ap, int);
	if (*arg->size != '\0')
	{
		while (ft_strcmp(arg->size, info->flags[ret]) == 1)
			ret++;
	}
	if (ret == 0)
		i = va_arg(ap, unsigned long long);
	else if (ret == 3)
		i = va_arg(ap, unsigned int);
	else if (ret == 1)
		i = va_arg(ap, unsigned int);
	else if (ret == 2)
		i = va_arg(ap, unsigned long long);
	tmp = ft_itoa_unsigned(i);
	return (tmp);
}

char	*u_fill_content(t_flags *info, t_arg *arg, va_list ap)
{
	char	*tmp;
	int		ret;

	tmp = u_flags(ap, arg, info);
	if (*tmp == '0' && arg->preci == 0)
	{
		free(tmp);
		return (ft_strdup(""));
	}
	ret = ft_strlen(tmp);
	if (arg->preci >= ret)
	{
		tmp = u_preci_malloc(arg, tmp, ret);
		ret = ft_strlen(tmp);
	}
	if (arg->width > ret)
		tmp = u_width_malloc(arg, tmp, ret);
	return (tmp);
}
