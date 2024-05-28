/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:25:27 by nrea              #+#    #+#             */
/*   Updated: 2023/11/14 14:38:32 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memmove() function copies n bytes from memory area src to memory area
dest.The memory areas may overlap: copying takes place as though the bytes
in  src are  first copied  into  a  temporary array that does not overlap
src or dest and the bytes are then copied from the temporary array to dest
The memmove() function returns a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	i = 0;
	if (cdest <= csrc)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	return (dest);
}
