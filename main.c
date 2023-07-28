/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:53:27 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/28 16:12:07 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

typedef struct s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_program;


// how to write pixels to image
// we need to get the mem address on which we will mutate the bytes acc
// to retrieve the address :

typedef struct s_data
{
	void	*img;
	char	*address;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	//put pixel on display every time a key is touchec?
	//mlx_pixel_put();
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
	
	// initialize the connection between my software and the display
	// mlx is the connection pointer
	mlx_ptr = mlx_init();
	
	// mlx_new_window is the 'window identifier' 
	// creates a new window on the screen 
	// returns a pointer to the window we've just created
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx 19");

	// draws a defined pixel in the window win_ptr using coordinates
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);

	// deal_key is the function pointer you want to call when an event occurs
	// void *param > the address will be passed to deal_key; 
	// should be used to store the parameters it might need
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	
	// writing pixels to image
	// start with pushing pixels to the window
	// initialize the image size 1920x1080
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	
	// handles keyboard or mouse events
	// inifinite loop that waits for an event
	mlx_loop(mlx_ptr);
	
	return (0); 	
}