/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:43:34 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 15:52:58 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If  c is a lowercase letter, toupper() returns its uppercase equivalent,
if an uppercase representation exists in the current locale.
Otherwise, it  returns  c.*/
int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	return (c);
}
