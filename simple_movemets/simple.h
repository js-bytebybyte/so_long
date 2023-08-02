/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:00:18 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/02 13:23:47 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H


# include "mlx.h"
# include <stdio.h>


/* -----------------------------------------------------------*/

#ifndef ANIMATION_FRAMES
# define ANIMATION_FRAMES 10
#endif


#define LEFT_KEY 123
#define RIGHT_KEY 124
#define UP_KEY	126
#define	DOWN_KEY 125		

/* ------------------STRUCTURES ---------------------------------*/

// for the connection and new window 

typedef struct s_image 
{
	void	*img_ptr;
	void	*address;
	int		width_x;
	int		heigth_y;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	sprite;
	int		x;
	int		y;
}	t_program;

/* ------------------ FUNCTIONS ---------------------------------*/

t_image	ft_sprite(void *mlx_ptr, char *path);

int	handle_input(int keycode, void *param);
int	ft_update (void *param);

#endif