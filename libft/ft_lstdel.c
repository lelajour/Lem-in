/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 12:29:49 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:31:18 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;
	t_list *nextlist;

	tmp = *alst;
	if (alst && del)
	{
		while (tmp != NULL)
		{
			nextlist = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = nextlist;
		}
	}
	*alst = NULL;
}
