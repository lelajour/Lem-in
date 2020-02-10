/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 22:18:48 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:11 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

int		ft_check_arg(const char *format, t_flags *info, t_arg *arg)
{
	int		i;
	int		ret;
	int		modul;

	i = 0;
	modul = 0;
	while (*format && info->line_arg[i])
	{
		ret = 0;
		if (*format == '%')
			modul++;
		if (*format == '%' && (ret = chkflag(&*format, info, i, arg)) == OK)
		{
			info->i_modu[i] = modul;
			format = ft_strchr(format + 1, info->line_arg[i]);
			arg = arg->next;
			i++;
		}
		else if (ret == MODULO || (ret == WRONG_FLAGS && *format != '\0'))
			clear_arg(arg, -1);
		else if (ret == WRONG_FLAGS && *format == '\0')
			end(info, arg, -1);
		format++;
	}
	return (OK);
}

int		check_flags(const char *format, int i, t_flags *info)
{
	int y;
	int len;

	while (*format != info->conv[i] && *format)
	{
		y = 0;
		if ((*format < '0' || *format > '9') && *format != info->conv[i])
		{
			while (info->flags[y])
			{
				len = ft_strlen(info->flags[y]);
				if (ft_strnequ(&*format, info->flags[y], len) == 1)
					break ;
				if (ft_strnequ(&*format, info->flags[y], len) == 0 && y == 11)
					return (WRONG_FLAGS);
				y++;
			}
			format += len;
		}
		while ((*format >= '0' && *format <= '9') || *format == '.')
			format++;
	}
	if (*format != info->conv[i])
		return (2);
	return (OK);
}

void	count_arg(const char *format, t_flags *info)
{
	int		i;
	int		tmp;

	tmp = 0;
	while (*format)
	{
		i = 0;
		while (info->conv[i] && *format == '%')
		{
			if (ft_strchr(&*(format + 1), info->conv[i]))
			{
				if ((tmp = check_flags(&*(format + 1), i, info)) >= OK)
				{
					info->line_arg = join_c(info->line_arg, info->conv[i]);
					info->nb_arg += tmp;
					format = ft_strchr(format + 1, info->conv[i]);
				}
			}
			i++;
		}
		format++;
	}
	info->i_modu = (int*)malloc(sizeof(int) * info->nb_arg);
}

int		ft_printf(const char *format, ...)
{
	t_flags		*info;
	va_list		ap;
	t_arg		*arg;
	t_arg		*tmp;

	if (!(arg = (t_arg*)malloc(sizeof(t_arg))))
		return (0);
	info = ft_fill_list();
	count_arg(format, info);
	arg = fill_t_arg(info, arg);
	if (!(ft_check_arg(format, info, arg) == OK))
		end(info, arg, -1);
	va_start(ap, format);
	tmp = arg;
	while (info->nb_arg-- > 0)
	{
		if (!(arg->content = test(arg, info, ap)))
			clear_arg(arg, -1);
		if (arg->next != NULL)
			arg = arg->next;
	}
	info->len_format += new_format(ft_strdup((char*)format), tmp, info, 0);
	return (end(info, tmp, -2));
}
