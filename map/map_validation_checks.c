/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/09 16:09:13 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/* functions to check the conditions to be met for a valid map */

//1. check if file is valid

int	valid_file(int argc, char *file)
{
	// the number of arguments is 1
	// printf("No arguments were passed.");
	if (argc == 1)
		return (0);

	// the number of arguments is higher than 2; so too many arguments
	// printf("Please only provide 1 map file.");
	if (argc > 2)
		return (0);

	// I need to check if the file has the rigth extension
	// printf("The file doesn't have the right extension");
	if (valid_file_extension(file, ".ber") == 0)
		return (0);
	return (1);
}

// 2. The map must be closed/surrounded by walls. If it’s not, the program must return

int ft_wall_check(t_map *game)
{
	int	i;
	int map_colums;
	int	map_rows;

	// check if the first row and the last row of the map contains only '1's 
	// this is the horizontal wall check
	i = 0;
	map_colums = game->columns; // 14
	map_rows = game->rows; // 5
	while (i < map_colums - 1) // 13 dus van 0 tem 12; \n is op plaats 13
	{
		
		if (game->map[0][i] != '1' || game->map[map_rows - 1][i] != '1')
			return (0);
		i++;
	}

	// check if the fist and last column of the map contains only '1's
	// this is the vertical wall check
	i = 0;
	while (i < map_rows) // 5 dus van 0 tem 4; \n is op plaats 13
	{
		if (game->map[i][0] != '1' || game->map[i][map_colums - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*

3. The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

4. The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.

*/

int	ft_char_check(t_map *game)
{
	int i;
	int j;
	
	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collectibles = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns - 1) 
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P')
				return (0);
			if (game->map[i][j] == 'P')
				game->player++;
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
	printf("player: %d,\nexit: %d,\ncollectibles: %d\n", game->player, game->exit, game->collectibles);
	if (game->player > 1 || game->exit > 1 || game->collectibles < 1)
		return (0);
	return (1);
}

void	set_start_end_position(t_map *game)
{
	int x; // move along the columns
	int	y; // move through the different rows

	game->start_x = 0;
	game->start_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns - 1)
		{
			if (game->map[y][x] == 'P')
			{
				game->start_x = x;
				game->start_y = y;
			}
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
	printf("the start position: (%d, %d)\n", game->start_y, game->start_x);
	printf("the exit position: (%d, %d)\n", game->exit_y, game->exit_x);
}
