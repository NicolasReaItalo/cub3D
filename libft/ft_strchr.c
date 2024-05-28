/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:22:07 by nrea              #+#    #+#             */
/*   Updated: 2023/11/20 10:01:35 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  strchr()  function  returns  a  pointer to the first occurrence of the
character c in the string s.*/
char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	cc;

	p = (char *) s;
	cc = (char) c;
	while (*p)
	{
		if (*p == cc)
			return (p);
		p++;
	}
	if (*p == cc)
		return (p);
	return (NULL);
}
