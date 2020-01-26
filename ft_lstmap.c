/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 04:53:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/24 05:20:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*np;

	new = malloc(sizeof(t_list));
	new->next = 0;
	if (!new)
		return (NULL);
	np = new;
	while (lst)
	{
		lst->content = f(lst->content);
		np->content = lst->content;
		lst = lst->next;
		if (lst)
		{
			np->next = malloc(sizeof(t_list));
			np->next->next = 0;
			np = np->next;
		}
	}
	return (new);
}
