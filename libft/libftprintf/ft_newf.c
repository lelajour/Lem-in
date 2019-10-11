/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newf.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 16:25:18 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:07 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

static int	c_null(t_arg *arg)
{
	int i;
	int	j;

	i = 1;
	if (arg->width != -2)
	{
		i = arg->width - 1;
		j = i;
		if (ft_strchr(arg->flags, '-'))
		{
			ft_putchar('\0');
			while (j--)
				write(1, " ", 1);
		}
		else
		{
			while (j--)
				write(1, " ", 1);
			ft_putchar('\0');
		}
		i++;
	}
	else
		ft_putchar('\0');
	return (i);
}

void		init(int *ret, t_arg **tmp, t_arg *arg)
{
	*ret = 0;
	*tmp = arg;
}

int			new_format(char *nformat, t_arg *arg, t_flags *info, int y)
{
	int		ret;
	t_arg	*tmp;

	tmp = NULL;
	init(&ret, &tmp, arg);
	while (nformat[++info->sctch] != '\0')
	{
		if (nformat[info->sctch] == '%' && ++ret == info->i_modu[y])
		{
			if (arg->type == 'c' && arg->c_i == 1)
				c_null(arg);
			else
				ft_putstr(arg->content);
			if (arg->type == '%')
				info->sctch++;
			while (nformat[info->sctch] != arg->type)
				info->sctch++;
			y++;
			if (arg->next != NULL)
				arg = arg->next;
		}
		else
			ft_putchar(nformat[info->sctch]);
	}
	return (count_len(nformat, tmp, info));
}
