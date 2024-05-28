/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:28 by nrea              #+#    #+#             */
/*   Updated: 2023/11/14 14:39:10 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memchr() function scans the initial n bytes of the memory area pointed
to by s for the first instance of c.  Both c and the bytes of the memory area
  pointed to by s are interpreted as unsigned char.
The memchr() and memrchr() functions return a pointer to the matching byte
 or NULL if the character does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cs = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (*(cs + i) == cc)
			return (cs + i);
		i++;
	}
	return (NULL);
}
