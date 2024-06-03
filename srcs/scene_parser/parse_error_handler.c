/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:40:28 by nrea              #+#    #+#             */
/*   Updated: 2024/06/03 13:49:32 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Simple wrapper for scene_loader an parse_scene to display the error*/
int	error_handler(int error_code)
{
	char	**errors;

	if (!error_code)
		return (0);
	errors = ft_split(ERROR_LIST, ';');
	write(2, "Error\n", 6);
	if (!errors)
		return (1);
	write(2, errors[error_code], ft_strlen(errors[error_code]));
	if (error_code == ERR_OPEN)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	ft_free_split(errors);
	return (error_code);
}
