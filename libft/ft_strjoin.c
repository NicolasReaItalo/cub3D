/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:06:21 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:56:58 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(size * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, (char *) s1, ft_strlen(s1) + 1);
	ft_strlcat(s, (char *) s2, size);
	return (s);
}
