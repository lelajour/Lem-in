/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   di_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/06 17:00:58 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:19 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*di_plus_malloc(char *tmp, t_arg *arg)
{
	char	*new_tmp;
	int		i;
	int		y;
	int		ye_no;

	y = 0;
	ye_no = 0;
	if (*tmp == '-')
		ye_no++;
	new_tmp = ft_strnew(ft_strlen(tmp) + 1);
	if (ft_strchr(arg->flags, ' ') && !(ft_strchr(arg->flags, '+')) && \
(*tmp != '-'))
		new_tmp[y] = ' ';
	else
	{
		i = ft_atoi(tmp);
		if (i >= 0 && *tmp != '-')
			new_tmp[y] = '+';
		else
			new_tmp[y] = '-';
	}
	new_tmp = ft_strcat(new_tmp, tmp + ye_no);
	free(tmp);
	return (new_tmp);
}

char	*di_flags(va_list ap, t_arg *arg, t_flags *info)
{
	char		*tmp;
	int			ret;

	ret = 0;
	tmp = NULL;
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
	if (ret == 0 || ret == 1)
		tmp = ft_itoa(va_arg(ap, int));
	else if (ret == 3)
		tmp = ft_itoa(va_arg(ap, int));
	else if (ret == 2 || ret == 4)
		tmp = ft_itoa(va_arg(ap, long long));
	return (tmp);
}

char	*di_preci_malloc(t_arg *arg, char *tmp, int ret)
{
	char	*buff;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (*tmp == '-' || *tmp == '+' || *tmp == ' ')
		len++;
	buff = ft_strnew(arg->preci + i + len);
	if (*tmp == '-' || *tmp == '+' || *tmp == ' ')
		ft_strcpy(buff + (arg->preci + i + len) - ret + i, tmp + i);
	else
		ft_strcpy(buff + (arg->preci + i + len) - ret, tmp);
	ft_memset(buff, '0', (arg->preci + i + len) - (ret - len));
	if (ft_strchr(arg->flags, '+') || *tmp == '-')
		if (*tmp == '-')
			*buff = '-';
		else
			*buff = '+';
	else if (ft_strchr(arg->flags, ' ') && *buff != '-')
		*buff = ' ';
	free(tmp);
	return (buff);
}

char	*last_check(char *buff, t_arg *arg)
{
	char	*str;
	char	c;

	if (ft_strequ(buff, "-'..--).0-*(+,))+(0("))
		return (real_last_check(buff));
	if (arg->preci == 0 && *buff == '0')
	{
		str = ft_strdup("");
		free(buff);
		return (str);
	}
	else if (arg->preci == 0 && *(buff + 1) == '0')
	{
		c = *buff;
		if (*buff == '+' || *buff == ' ')
		{
			str = ft_strdup(&c);
			free(buff);
			return (str);
		}
	}
	return (buff);
}

char	*real_last_check(char *buff)
{
	free(buff);
	return (ft_strdup("-9223372036854775808"));
}
