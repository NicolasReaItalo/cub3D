/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:57:11 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 16:09:30 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_line	*scene;
	int r;

	if (argc != 2)
		return (error_handler(ERR_USAGE));

	r = 0;
	r = init_data(&data);
	if (r)
		return(error_handler(r));

	r = load_scene(argv[1], &scene);
	if (r)
	{
		free_tex_path(&data);
		return (error_handler(r));
	}
	r = parse_scene(&scene,&data);
	if (r)
	{
		free_scene(&scene);
		free_map(data.map, data.map_h);
		free_tex_path(&data);
		return (error_handler(r));
	}
	free_scene(&scene);

	if (data.map == NULL)
	{
	free_tex_path(&data);
		return (error_handler(ERR_NO_MAP));
	}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////GAME

	printf("[DEBUG] data->f_color : [R]:[%d] [G]:[%d] [B]:[%d]\n", (data.f_color>>16)&0xFF, (data.f_color>>8)&0xFF,  data.f_color&0xFF);
	printf("[DEBUG] data->c_color : [R]:[%d] [G]:[%d] [B]:[%d]\n", (data.c_color>>16)&0xFF, (data.c_color>>8)&0xFF,  data.c_color&0xFF);
	printf("[DEBUG]data->N_path [%s]\n", data.n_img.path);
	printf("[DEBUG]data->S_path [%s]\n", data.s_img.path);
	printf("[DEBUG]data->E_path [%s]\n", data.e_img.path);
	printf("[DEBUG]data->W_path [%s]\n", data.w_img.path);

	int x = 0;
	int y = 0;

	printf("\n\n");
	while (y < data.map_h)
	{
		x = 0;
		while ( x < data.map_w)
		{

			// if ((float)x == data.pos.x && (float) y == data.pos.y)
			// 	printf("👨");
			// else if (data.map[y][x] == 9)
			// 	printf("X");
			// else if (data.map[y][x] == 1)
			// 	printf("█");
			// else if (data.map[y][x] == 0)
			// 	printf(" ");
			printf("%d", data.map[y][x]);

			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n\n");
	printf("The player start position is:[%f][%f]\n", data.pos.x, data.pos.y );
	printf("And is facing : ");
	if (data.dir.x == 0.f)
	{
		if (data.dir.y > 0)
			printf("S\n");
		else
			printf("N\n");
	}
	else if (data.dir.x > 0.f)
		printf("E\n");
	else
		printf("W\n");



//////////////END GAME
	free_map(data.map, data.map_h);
	free_tex_path(&data);




	return (SUCCESS);
}
