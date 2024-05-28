/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:47:55 by nrea              #+#    #+#             */
/*   Updated: 2023/11/21 11:41:37 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*allocates  memory  for  an  array of nmemb
elements of size bytes each and returns a pointer to the allocated memory.
The memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
either  NULL,  or a unique pointer value that can later be successfully
passed to free().  If the multiplication of nmemb and size would result in
 integer overflow, then calloc() returns an error.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!size || !nmemb)
		return (malloc(0));
	if ((size * nmemb) / size != nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
