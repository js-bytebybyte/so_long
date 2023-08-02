/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:13:23 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/02 11:34:19 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

t_image	ft_sprite(void *mlx_ptr, char *path)
{
	t_image image;
	
	// initialize the image -- return void pointer as the image initializer
	// Creates one that contains the .xpm image found in relative_path 
	// and saves its width and height in pixels to the given pointers. 
	image.img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &image.width_x, &image.heigth_y);
	
	// To manipulate the pixels of an image 
	// get the address of the bytes of the image
	image.address = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, &image.line_size, &image.endian);
	
	return (image);
}