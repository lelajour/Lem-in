/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 17:45:29 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:55 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

void	del_arg(t_arg *arg, int sig)
{
	t_arg *tmp;

	while (arg)
	{
		tmp = arg->next;
		clear_arg(arg, sig);
		free(arg);
		arg = NULL;
		arg = tmp;
	}
}

int		clear_arg(t_arg *arg, int sig)
{
	if (arg->flags)
	{
		free(arg->flags);
		arg->flags = NULL;
		if (sig == -1)
			arg->flags = ft_strnew(1);
	}
	if (arg->width)
		arg->width = -2;
	if (arg->preci)
		arg->preci = -2;
	if (arg->size)
	{
		free(arg->size);
		arg->size = NULL;
		if (sig == -1)
			arg->size = ft_strnew(1);
	}
	if (arg->content)
	{
		free(arg->content);
		arg->content = NULL;
	}
	return (0);
}

int		del_info(t_flags *info)
{
	int i;

	i = -1;
	if (info->conv)
	{
		free(info->conv);
		info->conv = NULL;
	}
	if (info->flags)
	{
		while (i++ < 11)
			free(info->flags[i]);
		free(info->flags);
		info->flags = NULL;
	}
	if (info->line_arg)
	{
		free(info->line_arg);
		info->line_arg = NULL;
	}
	if (info->i_modu)
		free(info->i_modu);
	free(info);
	info = NULL;
	return (0);
}

int		end(t_flags *info, t_arg *arg, int sig)
{
	int	ret;

	ret = info->len_format + info->len_arg;
	del_arg(arg, sig);
	if (sig == -2)
		del_info(info);
	return (ret);
}
