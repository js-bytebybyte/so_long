/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:38:36 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/15 16:22:31 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int  key_controls(int keycode, t_map *game)
{
    int x;
    int y;

    x = game->start_x;
    y = game->start_y;
    game->token = 0;
    printf("the start position: in keycontrol function (%d, %d)\n", game->start_y, game->start_x);
	if (keycode == ESC_KEY)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	else if (keycode == UP_KEY)
	{   
        printf("UP_KEY was pressed: %d\n", keycode);
        if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C') // the tile above is just the floor
        {
            if (game->map[y - 1][x] == 'C')
            {
                printf("Yummy, another candy in my tummy!\n");
                game->token++;
            }
            game->map[y][x] = '0'; // set the current position as floor 
            y -= 1; // go up along the vertical axis 
            game->map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned theredd
            printf("the new start position: in keycontrol function (%d, %d)\n", y, x);        
        }
        else
            return (0);
    }
	else if (keycode == DOWN_KEY)
    {
		printf("DOWN_KEY was pressed: %d\n", keycode);
        if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C') // the tile above is just the floor
        {
            if (game->map[y + 1][x] == 'C')
            {
                printf("Yummy, another candy in my tummy!\n");
                game->token++;
            }
            game->map[y][x] = '0'; // set the current position as floor 
            y += 1; // go up along the vertical axis 
            game->map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned theredd
            printf("the new start position: in keycontrol function (%d, %d)\n", y, x);        
        }
        else
            return (0);
    }
	else if (keycode == LEFT_KEY)
    {
		printf("LEFT_KEY was pressed: %d\n", keycode);
        if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C') // the tile above is just the floor
        {
            if (game->map[y][x - 1] == 'C')
            {
                printf("Yummy, another candy in my tummy!\n");
                game->token++;
            }
            game->map[y][x] = '0'; // set the current position as floor 
            x -= 1; // go up along the vertical axis 
            game->map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned theredd
            printf("the new start position: in keycontrol function (%d, %d)\n", y, x);        
        }
        else
            return (0);
    }
    else if (keycode == RIGHT_KEY)
    {
		printf("RIGHT_KEY was pressed: %d\n", keycode);
        if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C') // the tile above is just the floor
        {
            if (game->map[y][x + 1] == 'C')
            {
                printf("Yummy, another candy in my tummy!\n");
                game->token++;
            }
            game->map[y][x] = '0'; // set the current position as floor 
            x += 1; // go up along the vertical axis 
            game->map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned theredd
            printf("the new start position: in keycontrol function (%d, %d)\n", y, x);        
        }
        else
            return (0);
    }
    else
		printf("other key was pressed: %d\n", keycode);
    game->start_x = x;
    game->start_y = y;
    adding_in_graphics(game);
    printf("the number of tokens gathered: %d\n", game->token);
	return (0);
}

// player position
/*
the image has a position equal to start_x and start_y
*/