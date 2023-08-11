/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/11 13:08:07 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_game_images(t_game *game)
{
	t_graphics *items;
	int x;
	int	y;
	
	items->wall = mlx_xpm_file_to_image(game->mlx_ptr, "images/wall.xpm", &x, &y);
	items->floor = mlx_xpm_file_to_image(game->mlx_ptr, "images/floor.xpm", &x, &y);
	
}