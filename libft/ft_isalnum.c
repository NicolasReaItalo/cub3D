/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:01:06 by nrea              #+#    #+#             */
/*   Updated: 2023/11/17 14:31:20 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks for an alphanumeric character; it is equivalent to
(isalpha(c) ||isdigit(c)).*/
int	ft_isalnum(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (8);
	else if (c >= 'a' && c <= 'z')
		return (8);
	else if (c >= '0' && c <= '9')
		return (8);
	return (0);
}
