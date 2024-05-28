/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:45 by nrea              #+#    #+#             */
/*   Updated: 2024/01/02 11:31:44 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Create a node  with node->content = content
append the node at the end of the list if it exist or assign node to list
return the node create and assign the las_node pointer to it ( to save lines)*/
t_list	*ft_append_list(t_list **list, char *content, t_list **last_node)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
	if (!node->content)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	if (*list)
	{
		(ft_lstlast(*list))->next = node;
	}
	else
		*list = node;
	*last_node = node;
	return (node);
}

/*parse the list content until \n or until the end of the list if eof is set
 and calculate the nbr of characters needed to malloc
 Does not count the NULL character*/
int	ft_countchar(t_list *list, int eof)
{
	int	count;
	int	i;

	count = 0;
	while (list)
	{
		i = 0;
		while (((char *)(list->content))[i] != '\0')
		{
			count++;
			if (!eof)
			{
				if (((char *)(list->content))[i] == '\n')
					return (count);
			}
			i++;
		}
		list = list->next;
	}
	return (count);
}
