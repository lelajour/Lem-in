/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_arg.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 12:42:02 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:42 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

const char	*fo_param(t_arg *arg, const char *format, t_flags *info)
{
	int		y;
	int		ret;
	char	*tmp;

	y = 0;
	ret = 0;
	while (*format && y < 5)
	{
		if ((tmp = ft_strnstr((char*)format, info->flags[y], 2)))
		{
			free(arg->size);
			arg->size = NULL;
			arg->size = ft_strdup(info->flags[y]);
			if (y <= 1)
				return (format + 2);
			else
				return (++format);
		}
		y++;
	}
	return (format);
}

const char	*t_param(t_arg *arg, const char *format, t_flags *info)
{
	(void)info;
	if (*format == '.')
	{
		arg->preci = 0;
		format++;
	}
	if (*format == '*')
	{
		arg->preci = -1;
		return (++format);
	}
	if (*format >= '0' && *format <= '9')
	{
		arg->preci = 0;
		while (*format >= '0' && *format <= '9')
			arg->preci = (arg->preci * 10) + (*format++ - '0');
	}
	return (&*format);
}

const char	*s_param(t_arg *arg, const char *format, t_flags *info)
{
	(void)info;
	if (*format == '*')
	{
		arg->width = -1;
		return (++format);
	}
	if (*format >= '0' && *format <= '9')
	{
		arg->width = 0;
		while (*format >= '0' && *format <= '9')
			arg->width = (arg->width * 10) + (*format++ - '0');
	}
	return (format);
}

const char	*f_param(t_arg *arg, const char *format, t_flags *info)
{
	(void)info;
	while (*format && (*format == 35 || *format == 32 || *format == 43
		|| *format == 45 || *format == '0'))
	{
		if (ft_strchr(arg->flags, *format) == 0)
			arg->flags = join_c(arg->flags, *format);
		if (*format == '0' && *(format + 1) == '.')
		{
			arg->width = 0;
			return (++format);
		}
		format++;
	}
	return (&*format);
}

int			chkflag(const char *format, t_flags *info, int i, t_arg *arg)
{
	if (*(++format) != info->line_arg[i])
	{
		if ((format = f_param(arg, format, info)) == NULL)
			return (WRONG_FLAGS);
		if ((format = s_param(arg, format, info)) == NULL)
			return (WRONG_FLAGS);
		if ((format = t_param(arg, format, info)) == NULL)
			return (WRONG_FLAGS);
		if ((format = fo_param(arg, format, info)) == NULL)
			return (WRONG_FLAGS);
		else if (*format != info->line_arg[i])
			return (WRONG_FLAGS);
	}
	arg->type = info->line_arg[i];
	return (OK);
}
