/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:56:37 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:35:12 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*temp_s;
	char	*new_s;
	size_t	a;

	a = 0;
	new_s = NULL;
	if (s)
	{
		while (s[a] == '\t' || s[a] == '\n' || s[a] == ' ')
			a++;
		if (!(temp_s = ft_strdup((char*)&s[a])))
			return (NULL);
		a = 0;
		ft_strrev(temp_s);
		while (temp_s[a] && (temp_s[a] == '\t' || temp_s[a] == '\n' ||
		temp_s[a] == ' '))
			a++;
		new_s = ft_strdup((char*)&temp_s[a]);
		ft_strrev(new_s);
	}
	return (new_s);
}
