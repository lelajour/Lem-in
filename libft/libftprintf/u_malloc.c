/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   u_malloc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/09 18:28:13 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:39:56 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

char	*u_preci_malloc(t_arg *arg, char *tmp, int ret)
{
	char	*buff;

	buff = ft_memset(ft_strnew(arg->preci), '0', arg->preci);
	ft_strcpy(buff + arg->preci - ret, tmp);
	free(tmp);
	return (buff);
	return (tmp);
}

char	*u_width_malloc(t_arg *arg, char *tmp, int ret)
{
	char	*buff;

	buff = ft_memset(ft_strnew(arg->width), ' ', arg->width);
	if (ft_strchr(arg->flags, '-'))
		ft_strcpy(buff, tmp);
	else if (ft_strchr(arg->flags, '0') && arg->preci == -2)
	{
		ft_memset(buff, '0', arg->width);
		ft_strcpy(buff + arg->width - ret, tmp);
	}
	else
		ft_strcpy(buff + arg->width - ret, tmp);
	free(tmp);
	return (buff);
}
