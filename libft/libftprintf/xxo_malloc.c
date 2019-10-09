/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xxo_malloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 22:17:16 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:40:04 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*hashtag_width_neg_malloc(t_arg *arg, char *tmp, int ret)
{
	char	*buff;

	if (arg->type == 'x' || arg->type == 'X')
	{
		buff = ft_strnew(arg->width);
		ft_memset(buff, '0', arg->width);
		ft_strcpy(buff + (arg->width) - ret, tmp);
		if (*(tmp + 1) != arg->type && *tmp != '0')
			ft_strcpy(buff, "0x");
	}
	else
	{
		buff = ft_strnew(arg->width);
		ft_memset(buff, '0', arg->width);
		ft_strcpy(buff + (arg->width) - ret, tmp);
		if (*tmp != '0')
			buff[arg->width - ret - 1] = '0';
	}
	return (buff);
}

char	*hashtag_width_malloc(t_arg *arg, char *tmp, int ret)
{
	char *buff;

	buff = NULL;
	if (arg->preci == -2)
		buff = hashtag_width_neg_malloc(arg, tmp, ret);
	else
	{
		if (arg->type == 'x' || arg->type == 'X')
		{
			buff = ft_strnew(arg->width);
			ft_memset(buff, ' ', arg->width);
			ft_strcpy(buff + (arg->width) - ret, tmp);
			if (*(tmp + 1) != arg->type && *tmp != '\0')
				ft_strcpy(buff + arg->width - ret - 2, "0x");
		}
		else
		{
			buff = ft_strnew(arg->width);
			ft_memset(buff, ' ', arg->width);
			ft_strcpy(buff + (arg->width) - ret, tmp);
			if (*tmp != '0')
				buff[arg->width - ret - 1] = '0';
		}
	}
	return (buff);
}

char	*xxo_width_malloc(t_arg *arg, char *tmp, int ret)
{
	char *buff;

	if (ft_strchr(arg->flags, '-'))
	{
		buff = ft_memset(ft_strnew(arg->width), ' ', arg->width);
		ft_strcpy(buff, tmp);
	}
	else if (ft_strchr(arg->flags, '0') && ft_strchr(arg->flags, '#'))
		buff = hashtag_width_malloc(arg, tmp, ret);
	else if (ft_strchr(arg->flags, '0') && arg->preci == -2)
	{
		buff = ft_memset(ft_strnew(arg->width), '0', arg->width);
		ft_strcpy(buff + arg->width - ret, tmp);
	}
	else
	{
		buff = ft_memset(ft_strnew(arg->width), ' ', arg->width);
		ft_strcpy(buff + arg->width - ret, tmp);
	}
	free(tmp);
	return (buff);
}

char	*xxo_preci_malloc(t_arg *arg, char *tmp, int i)
{
	char	*buff;

	if (ft_strchr(arg->flags, '#') && arg->type != 'o' && *tmp != '0')
	{
		buff = ft_strnew(arg->preci + 2);
		ft_strncpy(buff + (arg->preci + 2) - i, tmp, i);
		ft_memset(buff, '0', arg->preci + 2 - i);
		buff[1] = arg->type;
	}
	else if (ft_strchr(arg->flags, '#') && arg->type == 'o' && i == arg->preci)
	{
		if (ft_strlen(tmp) == 1 && *tmp == '0')
			return (tmp);
		buff = ft_memset(ft_strnew(arg->preci + 1), '0', arg->preci + 1);
		ft_strcpy(buff + 1, tmp);
	}
	else
	{
		buff = ft_strnew(arg->preci);
		ft_strncpy(buff + (arg->preci) - i, tmp, i);
		ft_memset(buff, '0', arg->preci - i);
	}
	free(tmp);
	return (buff);
}

char	*neg_xx(char *tmp, t_arg *arg, int i)
{
	char	*str;
	int		len;

	str = NULL;
	if (arg->type == 'x')
	{
		if (!ft_strcmp(arg->size, "l") || !ft_strcmp(arg->size, "ll"))
			str = neg_xx_scotch(arg);
		else if (ft_strchr(arg->flags, '#'))
			str = ft_strdup("0xffffffff");
		else
			str = ft_strdup("ffffffff");
	}
	else
	{
		if (!ft_strcmp(arg->size, "l") || !ft_strcmp(arg->size, "ll"))
			str = neg_xx_scotch(arg);
		else if (ft_strchr(arg->flags, '#'))
			str = ft_strdup("0XFFFFFFFF");
		else
			str = ft_strdup("FFFFFFFF");
	}
	len = ft_strlen(str);
	ft_strcpy(str + len - i, tmp);
	return (str);
}
