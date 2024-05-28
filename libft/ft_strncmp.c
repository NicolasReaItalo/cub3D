/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:32:38 by nrea              #+#    #+#             */
/*   Updated: 2023/11/14 14:42:59 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strcmp() and strncmp() functions return an integer less than, equal to,
or greater  than  zero if  s1  (or  the  first  n bytes thereof) is found,
respectively, to be less than, to match, or be greater than s2.
 The sign of a nonzero return value shall be determined by the sign of
 the  difference  between the values of the first pair of bytes
 (both interpreted as type unsigned char) that differ in the strings
  being compared.*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (((s1 == NULL) && (s2 == NULL)) || (n == 0))
		return (0);
	i = 0;
	while (*s1 && *s2 && (i < (n - 1)) && (*s1 == *s2))
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
