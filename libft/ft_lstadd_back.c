/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:43:58 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:56:22 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Adds the node ’new’ at the end of the list.
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be
added to the list.*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}
