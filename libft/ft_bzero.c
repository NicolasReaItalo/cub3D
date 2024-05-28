/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:50:15 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 13:34:06 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  ft_bzero()  function erases the data in the n bytes of the memory
starting at the location pointed to by s, by writing zeros
(bytes containing '\0') to  that area.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned long int	i;
	unsigned char		*mem;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = '\0';
		i++;
	}
}
