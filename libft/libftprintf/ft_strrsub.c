/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 16:20:35 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 20:36:15 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*change_thing(char *str, int i, int y, const char *sub)
{
	char	*new_tmp;
	int		ret;
	int		b;
	int		t;

	b = ft_strlen(sub);
	t = ft_strlen(str);
	ret = b + t;
	new_tmp = ft_strnew(ret - y);
	new_tmp = ft_strncpy(new_tmp, str, i - y);
	new_tmp = ft_strcat(new_tmp, (char*)sub);
	new_tmp = ft_strcat(new_tmp, &str[i]);
	return (new_tmp);
}

char			*ft_strrsub(char *str, char *pat, char *sub, int i)
{
	int		y;
	char	*new_tmp;

	while (str[i])
	{
		y = 0;
		while (str[i] == pat[y] && pat[y])
		{
			i++;
			y++;
			if (pat[y] == '\0')
			{
				new_tmp = change_thing(str, i, y, sub);
				free(str);
				return (new_tmp);
			}
		}
		i++;
	}
	return (NULL);
}
