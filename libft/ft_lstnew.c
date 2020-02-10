/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 10:57:29 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:31:44 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nw_l;

	nw_l = NULL;
	if (!(nw_l = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!((nw_l->content) = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		nw_l->content = ft_memcpy(nw_l->content, (void*)content, content_size);
		nw_l->content_size = content_size;
	}
	else
	{
		nw_l->content = NULL;
		nw_l->content_size = 0;
	}
	nw_l->next = NULL;
	return (nw_l);
}
