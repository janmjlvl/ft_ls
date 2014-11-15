/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:40:35 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/10 14:56:10 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	if (lst)
	{
		dest = f(ft_lstnew(lst->content, lst->content_size));
		first = dest;
		lst = lst->next;
	}
	while (lst)
	{
		dest->next = f(ft_lstnew(lst->content, lst->content_size));
		dest = dest->next;
		lst = lst->next;
	}
	return (first);
}
