/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/08 16:48:42 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

	/* functions to check the conditions to be met for a valid map */

//1. check if file is valid

/*int	valid_file(int argc, char *file)
{
	// the number of arguments is 1
	if (argc == 1)
		printf("No arguments were passed.");

	// the number of arguments is higher than 2; so too many arguments
	if (argc > 2)
		printf("Please only provide 1 map file.");

	// I need to check if the file has the rigth extension
	if (!valid_file_extension(file, ".ber")
		printf("The file doesn't have the right extension");

	return (0);
}*/

// The map must be closed/surrounded by walls. If it’s not, the program must return

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
The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

The map must contain 1 exit, at least 1 collectible, and 1 starting position to
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
	if (game->player > 1 || game->exit > 1 || game->collectibles < 1)
		return (0);
	return (1);
}
