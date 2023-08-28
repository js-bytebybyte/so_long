/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:14 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/25 17:43:49 by jolandestee      ###   ########.fr       */
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
            // collectibles are not obstacles
            // if (game->map[i][j] == 'C')
            //     grid[i][j] = '0';
            // else    
            game->valid_path[i][j] = game->map[i][j];
            j++;
        }
        game->valid_path[i][j] = 0;
        i++;
    }
    game->valid_path[i] = 0;
    return (1);
}

static int ft_valid(int newX, int newY, t_map *game) 
{
    if (newX < 0)
        return (error("The column position lays outside of map.\n"));
    if (newX >= game->columns) // 5 dus van 0 tem 4
        return (error("The column position lays outside of map.\n")); 
    if (newY < 0)
        return (error("The row position lays outside of map.\n"));
    if (newY >= game->rows) // 3 dus van 0 tem 2 is max
        return (error("The column position lays outside of map.\n"));
    if (game->map[newY][newX] == '1')
        return (error("You've hit a wall.\n"));
    return (1);
}

static int move_x(int row_direction)
{
    if (row_direction == 2)
        return (-1);
    if (row_direction == 3)
        return (1);
    return (0);
}

static int move_y(int row_direction)
{
    if (row_direction == 0)
        return (-1);
    if (row_direction == 1)
        return (1);
    return (0);
}

int map_path_finder(t_map *game, int current_y, int current_x) 
{
    int     i;
    int     newY;
    int     newX;

    printf("The current position in path finder: (%d, %d)\n", current_y, current_x);
    printf("The exit position in path finder: (%d, %d)\n", game->exit_y, game->exit_x);
   
    // Destination reached
    if (current_y == game->exit_y && current_x == game->exit_x)
        return (1);
    
    // Mark the current position as visited > asign it value 2
    game->valid_path[current_y][current_x] = 2;
    
    i = 0;
    while (i < 4) 
    {
        newY = current_y + move_y(i);
        newX = current_x + move_x(i);
        // if (grid[newY][newX] == 'C')
        //     game->collectibles--;
        
        // check if the new direction is valid and that the value of the position is not visited yet
        if (ft_valid(newX, newY, game) && game->valid_path[newY][newX] != 2) 
        {
            if (map_path_finder(game, newY, newX))//&& game->collectibles == 0)
            {
                printf("There is a valid path!\n");
                return (1);
            }
        }
        i++;
    }
    return (0);
}

