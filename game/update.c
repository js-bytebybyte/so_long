/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:38:16 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/23 13:12:04 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	display_moves(t_map	*game)
{
	char	*s; // the text to write 
	
	s = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, IMG_SIZE / 4, IMG_SIZE / 4, -1, s);
	free(s);
}

int	update(t_map *game)
{
	// static int	frame;
	
	// // add a frame and every x frames change the position by 1 pixel
	// // so it looks like its animated
	// frame++;
	// if (frame == ANIMATION_FRAMES)
	// 	game->start_y += 1;
	// // every x*2 frames go back that pixel to loop the animation
	// else if (frame >= ANIMATION_FRAMES * 2)
	// {
	// 	game->start_y -= 1;
	// 	frame = 0;
	// }
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img, (game->start_x * IMG_SIZE), (game->start_y * IMG_SIZE));
	display_moves(game);
	return (0);	
}