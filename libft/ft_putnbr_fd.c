/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:26:35 by nrea              #+#    #+#             */
/*   Updated: 2023/11/13 17:47:07 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Outputs the integer ’n’ to the given file
descriptor.*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	if (fd < 0)
		return ;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + 48;
	write(fd, &c, 1);
}
