/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:57 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 15:39:47 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  strlen()  function calculates the length of the string
pointed to by s, excluding the terminating null byte ('\0').*/
size_t	ft_strlen(const char *s)
{
	unsigned int long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
