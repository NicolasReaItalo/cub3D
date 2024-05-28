/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:26 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 15:03:08 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strlcpy() function copies up to size - 1 characters from the
NUL-terminated string src to dst, NUL-terminating the result.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
		dest[i] = '\0';
	return (ft_strlen(src));
}
