/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:03:28 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/31 12:08:14 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

/*
mlx_image creates a new image in memory
return: void pointer id needed to manipulate the image later
parameters: size of the image (width + height) & mlx_ptr
The user can draw inside the image, 
dump the image inside a specified window to display it on the screen
using mlx_put_image_to_window

char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
- mlx_get_data_addr() returns information about the created image, allowing a user to modify it later. 
- The img_ptr parameter specifies the image to use. 
- The three next parameters should be the addresses of three different valid integers.
 > bits_per_pixel will be filled with the number of needed to represent a pixel color (also called the depth of the image). 
 > size_line is the number of bytes used to store one line of the image in memory. 
 	This information is needed to move from one line to another in the image. 	
 > endian tells you wether the pixel color in the image needs to be stored in little endian (endian == 0), 
 	or big endian ( endian == 1).

mlx_get_data_addr returns a char *address that represents the begining of the memory area where the image is stored. From this adress, the first bits_per_pixel bits represent the color of the first pixel in the first line of the image. The second group of bits_per_pixel bits represent the second pixel of the first line, and so on. Add size_line to the adress to get the begining of the second line. You can reach any pixels of the
image that way.

mlx_destroy_image destroys the given image (img_ptr ).

*/

typedef	struct s_data
{
	void	*img; // pointer to initialize the image
	char	*address; // address of the newly create image
	int		bits_per_pixel;
	int		line_length;
	int		endian;		
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		y;
	int		x;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello new window");

	// initialize the image
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	
	// write pixels to the image
	// we need to get the memory address on which we mutate the bytes accordingly
	// we have the image address, but no pixels
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	// the bytes are not aligned
	// line_length differs from the actual window width
	// we need to therefore always calculate the memory offset using the line length set by the above function
	y = 50;
	while (y < 100)
		my_mlx_pixel_put(&img, 50, y++, 0x00FFFF00);
	x = 50;
	while (x < 100)
		my_mlx_pixel_put(&img, x++, y, 0x00FFFF00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}