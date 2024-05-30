/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:40:28 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 14:27:31 by nrea             ###   ########.fr       */
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
	printf("Error\n");
	printf("%s", errors[error_code]);
	if (error_code == ERR_OPEN)
		printf("  %s", strerror(errno));
	printf("\n");
	ft_free_split(errors);
	return (error_code);
}
