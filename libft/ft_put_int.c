/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:18:30 by nrea              #+#    #+#             */
/*   Updated: 2023/12/13 11:51:08 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_int(int n)
{
	long	nb;
	int		count;
	int		neg;

	count = 0;
	neg = 0;
	nb = (long) n;
	if (nb < 0)
	{
		ft_put_char('-');
		nb *= -1;
		neg = 1;
	}
	if (nb >= 10)
		count += ft_put_int(nb / 10);
	count += ft_put_char((nb % 10) + 48);
	return (count + neg);
}
