/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:44:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/02 13:25:10 by jsteenpu         ###   ########.fr       */
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
	if (keycode == LEFT_KEY)
		program_ptr->x -= program_ptr->sprite.width_x;
	else if (keycode == RIGHT_KEY)
		program_ptr->x += program_ptr->sprite.width_x;
	else if (keycode == DOWN_KEY)
		program_ptr->y += program_ptr->sprite.heigth_y;
	else if (keycode == UP_KEY)
		program_ptr->y -= program_ptr->sprite.heigth_y;
	
	// put the image to the window
	mlx_put_image_to_window(program_ptr->mlx_ptr, program_ptr->win_ptr, program_ptr->sprite.img_ptr, program_ptr->x, program_ptr->y);
	
	// print the keycode pressed
	printf("Keycode pressed: %d\n", keycode);
	
	return (0);
}

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	// a static that saves how many frames have passed
	static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite.heigth_y += 10;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite.heigth_y -= 10;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx_ptr, program->win_ptr,
		program->sprite.img_ptr, program->x, program->y);
	return (0);
}