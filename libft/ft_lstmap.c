/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:55:36 by nrea              #+#    #+#             */
/*   Updated: 2024/01/02 11:20:39 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Use in case of a node allocation fails
del to clear the content and clear the list before returning NULL*/
static void	*ft_clear(t_list *new_lst, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&new_lst);
	return (NULL);
}

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*p;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	if (!content)
		return (NULL);
	new_lst = ft_lstnew(content);
	if (!new_lst || !content)
		return (ft_clear(new_lst, content, del));
	lst = lst->next;
	p = new_lst;
	while (lst)
	{
		content = f(lst->content);
		p->next = ft_lstnew(content);
		if (!p->next)
			return (ft_clear(new_lst, content, del));
		p = p->next;
		lst = lst->next;
	}
	return (new_lst);
}
