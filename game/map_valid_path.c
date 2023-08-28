/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:14 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/28 15:35:14 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// make temp grid to copy map

int init_valid_path(t_map *game)
{
    int     i;
    int     j;
    
    // create 6 hokjes, 0 to 5; 0 - 4 -> copy, bij i = 5 == 0
    game->valid_path = (char **)malloc(sizeof(char *) * (game->rows + 1)); //
    if (!game->valid_path)
        return (0);
    i = 0;    
    while (i < game->rows) // 5 rijen dus 5 hokjes, 0 -> 4; bij i = 5 > NULL
    {
        game->valid_path[i] = (char *)malloc(sizeof(char) * (game->columns + 1));
        if (!game->valid_path[i])
            return (0);
        j = 0;
        while (j < game->columns)
        {
            game->valid_path[i][j] = game->map[i][j];
            j++;
        }
        game->valid_path[i][j] = 0;
        i++;
    }
    game->valid_path[i] = 0;
    return (1);
}

int map_path_finder(t_map *game, int current_y, int current_x) 
{
    if (current_y < 0 || current_y >= game->rows || current_x < 0 || current_x >= game->columns) 
        return 0; // Out of bounds
    if (game->valid_path[current_y][current_x] == '1' || game->valid_path[current_y][current_x] == 'F' ||game->valid_path[current_y][current_x] == 'E' )
        return 0; // Already visited or a wall
    if (game->valid_path[current_y][current_x] == 'C')
        game->collectibles--;  
    
    // Mark the current position as visited > asign it value 2
    game->valid_path[current_y][current_x] = 'F';
    
    // fill every cell that is not equal to 
    map_path_finder(game, current_y - 1, current_x); // UP
    map_path_finder(game, current_y + 1, current_x); // DOWN
    map_path_finder(game, current_y, current_x - 1); // LEFT 
    map_path_finder(game, current_y, current_x + 1); // RIGHT
    
    if (game->collectibles == 0)
        return (1);

    return (0);
}

