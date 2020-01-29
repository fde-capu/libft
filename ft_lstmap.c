/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:48:25 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/29 13:03:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	**p;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst));
	if (!new)
		return (NULL);
	p = &new;
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew(f(lst));
		if (new)
		{
			ft_lstadd_back(p, new);
		}
		else
		{
			del(lst);
		}
	}
	return (*p);
}
