/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:14 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/29 12:02:52 by jsteenpu         ###   ########.fr       */
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

int map_path_finder(t_map *game, int current_y, int current_x, int tokens)
{
    if (current_y < 0 || current_y >= game->rows || current_x < 0 || current_x >= game->columns) 
        return 0; 
    if (game->flood_grid[current_y][current_x] == '1' || game->flood_grid[current_y][current_x] == 'F')
        return 0; 
    if (game->flood_grid[current_y][current_x] == 'C')
    {
        game->flood_grid[current_y][current_x] = 'F';    
        tokens--;
    }
    if (game->flood_grid[current_y][current_x] == 'E')
    {
        game->flood_grid[current_y][current_x] = 'F';    
        game->exit--;
    } 
    // Mark the current position as flooded ('F')
    game->flood_grid[current_y][current_x] = 'F';
    
    // recursive call for every direction possible
    map_path_finder(game, current_y - 1, current_x, tokens); // UP
    map_path_finder(game, current_y + 1, current_x, tokens); // DOWN
    map_path_finder(game, current_y, current_x - 1, tokens); // LEFT 
    map_path_finder(game, current_y, current_x + 1, tokens); // RIGHT

    // the map is valid only if all tokens have been 'flooded'
    if (tokens == 0 && game->exit == 0)
        return (1);
    
    return (0);
}
