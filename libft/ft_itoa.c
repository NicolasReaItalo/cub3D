/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:42:05 by nrea              #+#    #+#             */
/*   Updated: 2023/11/13 14:51:13 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Return the number of digits needed to write the integer
doesn' t count NULL character or negative sign */
static int	ft_count_digits(int n)
{
	long int	nb;
	int			digits;

	digits = 1;
	nb = n;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

/*Return the 10 power needed to divide nb and obtain the first digit*/
long int	ft_get_div(long int nb)
{
	long int	div;

	div = 1;
	while (nb > 9)
	{
		div *= 10;
		nb /= 10;
	}
	return (div);
}

/* iterate trough the string ret_s to append digits of the long int nb
starting at index i.
NULL terminate the string*/
void	ft_append_digits(char *ret_s, long int nb, int i)
{
	long int	div;

	div = ft_get_div(nb);
	while (div >= 1)
	{
		ret_s[i] = (nb / div) + 48;
		nb %= div;
		div /= 10;
		i++;
	}
	ret_s[i] = '\0';
}

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
Return value : The string representing the integer.
NULL if the allocation fails.*/
char	*ft_itoa(int n)
{
	int			digits_nb;
	int			sign;
	long int	nb;
	char		*ret_s;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb *= -1;
	}
	digits_nb = ft_count_digits(nb);
	ret_s = malloc((digits_nb + sign + 1) * sizeof(char));
	if (!ret_s)
		return (NULL);
	if (sign)
	{
		ret_s[0] = '-';
		ft_append_digits(ret_s, nb, 1);
	}
	else
		ft_append_digits(ret_s, nb, 0);
	return (ret_s);
}
