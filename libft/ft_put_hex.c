/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:39:40 by nrea              #+#    #+#             */
/*   Updated: 2023/12/13 11:51:08 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hex(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		count += ft_put_hex(nbr / base_len, base);
	count += ft_put_char(base[nbr % base_len]);
	return (count);
}
