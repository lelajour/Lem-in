/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:54:24 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 17:54:50 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		a;

	str = NULL;
	if (s1 && s2)
	{
		a = ft_strlen(s1) + ft_strlen(s2);
		str = ft_strnew(a);
		ft_strcpy(str, s1);
		ft_strcat(str, (char*)s2);
	}
	return (str);
}
