/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:25 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:28:24 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Checks if the character c belongs to definition of space
given by man 3 isspace
return 1 on success / 0 on failure*/
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

/*The  atoi()  function converts the initial portion of the string
pointed to by nptr to int.
RETURN VALUE : The converted value or 0 on error.*/
int	ft_atoi(const char *nptr)
{
	int	ret_value;
	int	sign;

	ret_value = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		ret_value = (ret_value * 10) + *nptr - 48;
		nptr++;
	}
	return (ret_value * sign);
}
