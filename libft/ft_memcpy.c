/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:23:39 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:50:50 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memcpy()  function  copies  n bytes from memory area src to memory
area dest.
The memory areas must not overlap.  Use memmove(3) if the memory areas do
overlap.
The memcpy() function returns a pointer to dest.*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cdest;
	char	*csrc;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	cdest = (char *) dest;
	csrc = (char *) src;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
