/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:28:48 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:55:43 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strdup()  function returns a pointer to a new string which
is a duplicate of the string s.  Memory for the new string is obtained with
malloc(3), and  can  be freed with free
On success, the strdup() function returns a pointer to the duplicated string.
It returns  NULL if insufficient memory was available, with errno set to
indicate the cause of the error.*/
char	*ft_strdup(const char *s)
{
	size_t	s_size;
	char	*dup;
	int		i;

	i = 0;
	s_size = ft_strlen(s) + 1;
	dup = malloc(s_size * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
