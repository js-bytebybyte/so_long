/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_reading_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:28:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/31 12:49:22 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*filename = "minion.xpm";
	int		img_width;
	int		img_height;
	int		check;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Reading image");
	img = mlx_xpm_file_to_image(mlx_ptr, filename, &img_width, &img_height);
	check = mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_loop(mlx_ptr);	
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "minion.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// }
