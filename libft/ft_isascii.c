/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:12:47 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:34:52 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether c is a 7-bit unsigned char value that fits into the ASCII
character set.*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
