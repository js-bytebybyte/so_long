/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:03:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/01 13:28:25 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"


int	handle_input(int keycode, void *param)
{
	t_program	*program_ptr;

	// initializing the void t_program_ptr and typecasting 
	program_ptr = (t_program *)param;

	// if no event is hooked, close the window ?
	mlx_clear_window(program_ptr->mlx_ptr, program_ptr->win_ptr);
	
	// move in the correct direction using the keycodes
	// move in relation to the size of the image
	if (keycode == 123) // LEFT KEY
		program_ptr->x -= program_ptr->image.image_width_x;
	if (keycode == 124) // RIGTH KEY
		program_ptr->x += program_ptr->image.image_width_x;
	if (keycode == 125) // DOWN KEY
		program_ptr->y += program_ptr->image.image_heigth_y;
	if (keycode == 126) // UP KEY
		program_ptr->y -= program_ptr->image.image_heigth_y;
	
	// put the image to the window
	mlx_put_image_to_window(program_ptr->mlx_ptr, program_ptr->win_ptr, program_ptr->image.image_ptr, program_ptr->image.image_width_x, program_ptr->image.image_heigth_y);
	
	printf("Keycode pressed: %d\n", keycode);
	
	return (0);
}

int	main(void)
{
	t_image		*img;
	char		*filename = "cursor.xpm";
	t_program	program;
	int			width;
	int			heigth;
	
	// initialize the connection
	program.mlx_ptr = mlx_init();

	// open new window - window connector
	program.win_ptr = mlx_new_window(program.mlx_ptr, 1920, 1080, "My first simple game");

	// import image
	// how to resize an image
	img->img_ptr = mlx_xpm_file_to_image(program.mlx_ptr, filename, &img->image_width_x, &img->image_heigth_y);

	// put image to window at x = 0 and y = 0
	//mlx_put_image_to_window(program.mlx_ptr, program.win_ptr, img, 0, 0);

	// hooks setup 
	mlx_key_hook(program.win_ptr, *handle_input, &program);

	
	// keep the window opem
	mlx_loop(program.mlx_ptr);
	
	return (0);
}