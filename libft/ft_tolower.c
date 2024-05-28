/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:05:38 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 15:51:11 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If c is an uppercase letter, tolower() returns its lowercase equivalent,
if a lowercase representation exists in the current locale.
Otherwise, it returns c.*/
int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	return (c);
}
