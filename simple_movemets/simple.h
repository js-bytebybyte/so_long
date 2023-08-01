/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:00:18 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/01 13:07:21 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H


# include "mlx.h"
# include <stdio.h>

/* ------------------STRUCTURES ---------------------------------*/

// for the connection and new window 

typedef struct s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	image;
	int		x;
	int		y;
}	t_program;

typedef struct s_image 
{
	void	*img_ptr;
	int		image_width_x;
	int		image_heigth_y;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;


#endif