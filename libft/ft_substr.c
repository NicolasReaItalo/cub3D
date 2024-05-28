/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:36 by nrea              #+#    #+#             */
/*   Updated: 2023/11/15 11:14:53 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocate and return a '\0' string*/
char	*ft_empty_str(void)
{
	char	*ret;

	ret = malloc(sizeof(char));
	if (!ret)
		return (NULL);
	*ret = '\0';
	return (ret);
}

/*Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_empty_str());
	if (start + len > ft_strlen(s))
	len = ft_strlen(s) - start;
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
