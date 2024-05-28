/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:54:37 by nrea              #+#    #+#             */
/*   Updated: 2023/11/10 18:36:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_isinset : check if the char c is in the charset set return 1 if success*/
static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/*ft_counttrim : count the number of char after head and tail trimmed
doesn't count the null char.
return the character numbers;
*/
static unsigned int	ft_counttrim(const char *s, char const *set)
{
	int	tail_index;

	while (*s && ft_isinset(*s, set))
		s++;
	tail_index = ft_strlen(s) -1;
	while (ft_isinset(s[tail_index], set) && tail_index >= 0)
		tail_index--;
	return (tail_index + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	size;
	unsigned int	i;
	char			*p;

	if (!s1 || !set)
		return (NULL);
	size = ft_counttrim(s1, set) + 1;
	p = (char *) malloc(size * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1 && ft_isinset(*s1, set))
	s1++;
	i = 0;
	while (i < size - 1)
	{
		p[i] = s1[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}
