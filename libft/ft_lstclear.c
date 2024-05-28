/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:32:27 by nrea              #+#    #+#             */
/*   Updated: 2024/01/02 10:31:12 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*free all the nodes and content in a list and return NULL*/
void	*ft_lstclear(t_list **lst)
{
	t_list	*p;
	t_list	*p2;

	if (!lst)
		return (NULL);
	p = *lst;
	*lst = NULL;
	while (p)
	{
		if (p->content)
			free(p->content);
		p2 = p;
		p = p->next;
		free(p2);
	}
	return (NULL);
}
