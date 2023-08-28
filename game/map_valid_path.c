/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:14 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/28 17:39:57 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// make temp 2D array called 'flood_grid' to copy the 2D array 'map'
int init_valid_path(t_map *game)
{
    int     i;
    int     j;
    
    game->flood_grid = (char **)malloc(sizeof(char *) * (game->rows + 1)); 
    if (!game->flood_grid)
        return (0);
    i = 0; 
    while (i < game->rows)
    {
        game->flood_grid[i] = (char *)malloc(sizeof(char) * (game->columns + 1));
        if (!game->flood_grid[i])
            return (0);
        j = 0;
        while (j < game->columns)
        {
            game->flood_grid[i][j] = game->map[i][j];
            j++;
        }
        game->flood_grid[i][j] = 0;
        i++;
    }
    game->flood_grid[i] = 0;
    return (1);
}

int map_path_finder(t_map *game, int current_y, int current_x) 
{
    int tokens;
    
    tokens = game->collectibles;
    if (current_y < 0 || current_y >= game->rows || current_x < 0 || current_x >= game->columns) 
        return 0; 
    if (game->flood_grid[current_y][current_x] == '1' || 
        game->flood_grid[current_y][current_x] == 'F' ||
        game->flood_grid[current_y][current_x] == 'E' )
        return 0; 
    if (game->flood_grid[current_y][current_x] == 'C')
        tokens--;  
    
    // Mark the current position as flooded ('F')
    game->flood_grid[current_y][current_x] = 'F';
    
    // recursive call for every direction possible
    map_path_finder(game, current_y - 1, current_x); // UP
    map_path_finder(game, current_y + 1, current_x); // DOWN
    map_path_finder(game, current_y, current_x - 1); // LEFT 
    map_path_finder(game, current_y, current_x + 1); // RIGHT

    // the map is valid only if all tokenss have been encountered
    if (tokens == 0)
        return (1);
    
    return (0);
}

