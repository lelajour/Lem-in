/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 22:17:28 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:38:59 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

t_arg	*fill_t_arg(t_flags *info, t_arg *arg)
{
	static int		i = 0;
	static t_arg	*tmp;

	arg->flags = ft_strnew(0);
	arg->width = -2;
	arg->preci = -2;
	arg->size = ft_strnew(0);
	arg->type = '\0';
	arg->content = NULL;
	arg->next = NULL;
	if (i == 0)
		tmp = arg;
	while (++i < info->nb_arg)
	{
		while (arg->next != NULL)
			arg = arg->next;
		if (!(arg->next = (t_arg*)malloc(sizeof(t_arg))))
			return (NULL);
		arg = arg->next;
		return (fill_t_arg(info, arg));
	}
	if (i > 1)
		arg = tmp;
	i = 0;
	return (arg);
}

t_flags	*ft_fill_list(void)
{
	t_flags *info;

	info = (t_flags*)malloc(sizeof(t_flags));
	info->nb_arg = 0;
	info->conv = ft_strdup("spdiouxXcf%");
	info->i_modu = NULL;
	info->len_arg = 0;
	info->len_format = 0;
	if (!(info->flags = (char**)malloc(sizeof(char*) * 12)))
		return (NULL);
	info->flags[0] = ft_strdup("ll");
	info->flags[1] = ft_strdup("hh");
	info->flags[2] = ft_strdup("l");
	info->flags[3] = ft_strdup("h");
	info->flags[4] = ft_strdup("L");
	info->flags[5] = ft_strdup(".");
	info->flags[6] = ft_strdup(" ");
	info->flags[7] = ft_strdup("+");
	info->flags[8] = ft_strdup("-");
	info->flags[9] = ft_strdup("0");
	info->flags[10] = ft_strdup("#");
	info->flags[11] = ft_strdup("*");
	info->line_arg = ft_strnew(0);
	info->sctch = -1;
	return (info);
}

char	*join_c(char *str, char c)
{
	char	*tmp;
	int		i;

	i = ft_strlen(str) + 1;
	tmp = ft_strnew(i);
	ft_strcpy(tmp, str);
	tmp[i - 1] = c;
	free(str);
	str = NULL;
	return (tmp);
}
