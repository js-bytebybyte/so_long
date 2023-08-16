/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/16 12:11:43 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int  key_controls(int keycode, t_map *game)
{
    game->token = 0;
    printf("the start position: in keycontrol function (%d, %d)\n", game->start_y, game->start_x);
	if (keycode == ESC_KEY)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	else if (keycode == UP_KEY)
        game->start_y = move_up(game->map, game->start_y, game->start_x, game->token);
	else if (keycode == DOWN_KEY)
        game->start_y = move_down(game->map, game->start_y, game->start_x, game->token);
    else if (keycode == LEFT_KEY)
        game->start_x = move_left(game->map, game->start_y, game->start_x, game->token);
    else if (keycode == RIGHT_KEY)
        game->start_x = move_right(game->map, game->start_y, game->start_x, game->token);
    else
		printf("other key was pressed: %d\n", keycode);
    if (game->start_x || game->start_y)
        terminate_game();
    adding_in_graphics(game);
    printf("the number of tokens gathered: %d\n", game->token);
	return (0);
}