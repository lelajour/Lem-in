/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   len_return_scotch.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:59:46 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:38 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*cat_format(char *nformat, t_arg *arg, int i)
{
	int		ret;
	char	*tmp;
	int		t;

	ret = i;
	t = 0;
	tmp = NULL;
	if (arg->type == '%')
		i++;
	while (nformat[i] != arg->type)
		i++;
	tmp = ft_strnew((i - ret + 1));
	while (ret <= i)
	{
		tmp[t] = nformat[ret];
		t++;
		ret++;
	}
	nformat = ft_strrsub(nformat, tmp, arg->content, ret - t);
	free(tmp);
	return (nformat);
}

char	*clear_nformat(char *nformat, int i)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(nformat) - 1);
	tmp = ft_strncpy(tmp, nformat, i);
	tmp = ft_strcat(tmp, nformat + i + 1);
	free(nformat);
	return (tmp);
}

int		count_len(char *nformat, t_arg *arg, t_flags *info)
{
	int		i;
	int		y;
	int		ret;

	i = 0;
	y = 0;
	ret = 0;
	while (nformat[i] && y < ft_strlen(info->line_arg))
	{
		if (nformat[i] == '%')
		{
			if (++ret == info->i_modu[y])
			{
				nformat = cat_format(nformat, arg, i);
				i += ft_strlen(arg->content) - 1;
				y++;
				arg = arg->next;
			}
			else
				nformat = clear_nformat(nformat, i);
		}
		i++;
	}
	return (retrn(nformat));
}

int		retrn(char *nformat)
{
	int	ret;

	ret = ft_strlen(nformat);
	free(nformat);
	return (ret);
}
