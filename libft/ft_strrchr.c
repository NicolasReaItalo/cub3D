/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:59:25 by nrea              #+#    #+#             */
/*   Updated: 2023/11/20 09:18:49 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strrchr() function returns a pointer to the  last  occurrence
 of the character c in the string s.*/
char	*ft_strrchr(const char *s, int c)
{
	int		tail;
	char	*p;
	char	cc;

	p = (char *) s;
	cc = (char) c;
	tail = ft_strlen(s);
	while (tail > 0)
	{
		if (p[tail] == cc)
			return (p + tail);
		tail--;
	}
	if (p[tail] == cc)
		return (p + tail);
	return (NULL);
}
