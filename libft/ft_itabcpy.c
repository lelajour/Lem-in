/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itabcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:27:26 by lelajour          #+#    #+#             */
/*   Updated: 2019/11/25 07:31:24 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		*ft_itabdup(int *tab, int len)
{
	int		*new;
	int		i;

	i = 0;
	new = ft_memalloc(len);
	while (i < len)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
