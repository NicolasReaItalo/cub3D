/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:17:34 by nrea              #+#    #+#             */
/*   Updated: 2023/11/21 10:51:45 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strnstr() function locates the first occurrence of the null-terminated
string little in the string big, where not more than len characters are
searched.Characters that appear after a ‘\0’ character are not searched.
If little is an empty string, big is returned; if little occurs nowhere
in big, NULL is returned; otherwise a pointer to the first character of
the first occurrence of little is returned.
	 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	c;

	if (!len && (!big || !little))
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	c = 0;
	while (*big && (c + ft_strlen(little) <= len))
	{
		if (!ft_strncmp(big + c, little, ft_strlen(little)))
			return ((char *)(big + c));
		c++;
	}
	return (NULL);
}
