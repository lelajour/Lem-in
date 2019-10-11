/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   di_conv.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 16:42:43 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:15 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*di_cpy(char *buff, char *tmp, int ret)
{
	int i;
	int y;
	int	ye_no;

	if (*tmp == '-' || *tmp == '+' || *tmp == ' ')
		ret--;
	i = ft_strlen(buff) - ret;
	y = 0;
	ye_no = ft_isdigit(*tmp);
	if (ye_no == 0)
		while ((ye_no = ft_isdigit(tmp[y])) != 1 && tmp[y])
			y++;
	while (tmp[y])
		buff[i++] = tmp[y++];
	return (buff);
}

char	*di_width_malloc(char *tmp, t_arg *arg, int ret, char *buff)
{
	if (arg->width >= ret)
	{
		ft_memset(buff, ' ', arg->width);
		if (ft_strchr(arg->flags, '-') || (arg->preci != -2))
		{
			if (ft_strchr(arg->flags, '-') && !(arg->preci == 0 && *tmp == '0'))
				ft_memcpy(buff, tmp, ret);
			else if (!(arg->preci == 0 && *tmp == '0'))
				ft_memcpy(buff + arg->width - ret, tmp, ret);
		}
		else if (ft_strchr(arg->flags, '0'))
		{
			buff = ft_memset(buff, '0', arg->width);
			if (*tmp == '-' || *tmp == '+' || *tmp == ' ')
				buff[0] = tmp[0];
			buff = di_cpy(buff, tmp, ret);
		}
		else
			di_cpy(buff, tmp, ret);
		if ((*tmp == '-' || *tmp == '+') && !ft_strchr(arg->flags, '0'))
			buff[arg->width - ret] = scotch(arg, *tmp, buff[arg->width - ret]);
	}
	else
		buff = ft_strdup(tmp);
	return (buff);
}

char	scotch(t_arg *arg, char c, char b)
{
	if (!ft_strchr(arg->flags, '-'))
		return (c);
	else
		return (b);
}

char	*di_fill_content(t_arg *arg, va_list ap, t_flags *info)
{
	char	*buff;
	char	*tmp;
	int		ret;

	tmp = di_flags(ap, arg, info);
	if (ft_strchr(arg->flags, '+') || ft_strchr(arg->flags, ' '))
		tmp = di_plus_malloc(tmp, arg);
	ret = ft_strlen(tmp);
	if (arg->preci >= ret)
		tmp = di_preci_malloc(arg, tmp, ret);
	ret = ft_strlen(tmp);
	if (arg->width >= arg->preci)
	{
		if (arg->width >= ret)
			buff = ft_strnew(arg->width);
		if (*tmp == '-' && (ft_strchr(arg->flags, '0') && arg->preci != -2))
			buff = di_width_malloc(tmp, arg, ret, buff);
		else
			buff = di_width_malloc(tmp, arg, ret, buff);
	}
	else
		buff = ft_strdup(tmp);
	free(tmp);
	buff = last_check(buff, arg);
	return (buff);
}
