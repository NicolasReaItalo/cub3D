/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:56:36 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 15:48:21 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
Return value : The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	ret_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret_s)
		return (NULL);
	while (s[i])
	{
		ret_s[i] = f(i, s[i]);
		i++;
	}
	ret_s[i] = '\0';
	return (ret_s);
}
