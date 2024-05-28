/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:12:25 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:48:54 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memcmp() function compares the first n bytes
(each interpreted as unsigned char) of the memory areas s1 and s2.
The memcmp() function returns an integer less than, equal to, or  greater
than zero  if  the  first  n bytes of s1 is found, respectively, to be less
than, tomatch, or be greater than the first n bytes of s2.

For a nonzero return value, the sign is determined by the sign of  the
difference between the first pair of bytes (interpreted as unsigned char)
that differ in s1 and s2.

If n is zero, the return value is zero.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	while (n)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		n--;
	}
	return (0);
}
