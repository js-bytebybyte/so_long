/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:03:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/02 13:24:21 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"
#include <stdio.h>


// int test(int key)
// {
// 	printf("key = %d\n", key);
// 	return (0);
// }

int	main(void)
{
	char		*filename = "minion.xpm";
	t_program	program;
	
	// initialize the connection
	program.mlx_ptr = mlx_init();

	// open new window - window connector
	program.win_ptr = mlx_new_window(program.mlx_ptr, 1920, 1080, "My first simple game");

	// create a new image -- return the initialized image
	// this is the new sprite
	program.sprite = ft_sprite(program.mlx_ptr, filename);
	program.x = 0;
	program.y = 0;
	mlx_put_image_to_window(program.mlx_ptr, program.win_ptr, program.sprite.img_ptr, program.x, program.y);
	
	/* hooks setup */
	//mlx_key_hook(program.win_ptr, &test, NULL);
	mlx_key_hook(program.win_ptr, *handle_input, &program);
	mlx_loop_hook(program.mlx_ptr, *ft_update, &program);
	
	// keep the window opem
	mlx_loop(program.mlx_ptr);
	
	return (0);
}