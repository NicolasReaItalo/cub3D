/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:53:24 by nrea              #+#    #+#             */
/*   Updated: 2023/12/13 11:49:53 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base_l(unsigned long nbr, char *base)
{
	unsigned long	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		count += ft_putnbr_base_l(nbr / base_len, base);
	count += ft_put_char(base[nbr % base_len]);
	return (count);
}

int	ft_put_ptr(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_put_str("(nil)"));
	count += ft_put_str("0x");
	count += ft_putnbr_base_l((unsigned long) p, "0123456789abcdef");
	return (count);
}
