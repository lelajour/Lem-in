/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 17:07:16 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:31:39 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_l;
	t_list	*tmp_l;

	new_l = NULL;
	tmp_l = NULL;
	if (lst && f)
	{
		new_l = f(lst);
		tmp_l = new_l;
		while (lst->next != NULL)
		{
			lst = lst->next;
			if (!(tmp_l->next = f(lst)))
				return (NULL);
			tmp_l = tmp_l->next;
		}
		return (new_l);
	}
	return (NULL);
}
