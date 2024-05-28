/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:35:37 by nrea              #+#    #+#             */
/*   Updated: 2023/11/21 11:27:23 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcat() function appends the NUL-terminated string src to the end of
dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
     the result.
returns the total length of the
     string they tried to create that means the initial length of dst
	 plus the length of src
*/
size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] && i < (size - dest_len - 1))
	{
		dest[i + dest_len] = src[i];
		i++;
	}
		dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}
