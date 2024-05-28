/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:27:52 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:52:22 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memset()  function fills the first n bytes of the memory area pointed
to by s with the constant byte c.
The memset() function returns a pointer to the memory area s.*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;

	mem = s;
	while (n > 0)
	{
		*mem = (unsigned char) c;
		mem++;
		n--;
	}
	return (s);
}
