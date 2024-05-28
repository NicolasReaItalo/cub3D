/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:30:38 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:32:17 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks  for an alphabetic character;
in the standard "C" locale, it is equivalent to (isupper(c) || islower(c)).*/
int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1024);
	else if (c >= 'a' && c <= 'z')
		return (1024);
	return (0);
}
