/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imemcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:28:35 by lelajour          #+#    #+#             */
/*   Updated: 2019/12/05 05:19:37 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_imemcmp(const void *s1, const void *s2, size_t n)
{
	int			a;
	const int	*temp_s1;
	const int	*temp_s2;

	temp_s1 = s1;
	temp_s2 = s2;
	a = 0;
	if (n)
	{
		while (--n && (temp_s1[a] == temp_s2[a]))
			a++;
		return ((unsigned int)temp_s1[a] - (unsigned int)temp_s2[a]);
	}
	return (0);
}
