/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/30 10:54:21 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/* 1. check if the map .ber file is correct */ 

static int	valid_file(int argc, char *file)
{
	if (!argc)
		return (error("Valid file failure."));
	if (argc == 1)
		return (error("Please provide 1 map.ber file as argument."));
	if (argc > 2)
		return (error("Please provide just one map.ber file."));
	if (!valid_file_extension(file, ".ber"))
		return (error("Incorrect file extension. Please provide a .ber file."));
	return (1);
}

/* 2. The map must be closed/surrounded by walls. */

static int walls_check(t_map *game)
{
	int	i;

	i = 0;
	while (i < game->columns) // horizontal check 
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->rows) // vertical check
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* 3. The map can only be composed of the following 5 characters */

static int	valid_chars_check(t_map *game)
{
	int i;
	int j;
	
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns) 
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'C' 
				&& game->map[i][j] != 'E' && game->map[i][j] != 'P')
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
	if (game->player == 0 || game->exit == 0 || game->collectibles < 1)
		return (0);
	return (1);
}

/* if all OK, look for the player's start and the exit position */

static void	set_start_and_exit(t_map *game)
{
	int x; 
	int	y; 

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				game->start_p.x = x;
				game->start_p.y = y;
				printf("Map init: the start position (y: %d, x: %d)\n", game->start_p.y, game->start_p.x);
			}
			if (game->map[y][x] == 'E')
			{
				game->exit_p.x = x;
				game->exit_p.y = y;
				printf("Map init: the exit position (y: %d, x: %d)\n", game->exit_p.y, game->exit_p.x);
			}
			x++;
		}
		y++;
	}
}

// Includes all the check functions + sets start and exit position 

int	map_init_checks(t_map *game, int argc, char *map_file)
{
	int	tokens;

	if (!valid_file(argc, map_file))
		return (0);
	if (!map_reading(game, map_file))
		return (error("Failure to read the map.\n"));
	if (!walls_check(game))
		return (error("The map is not surrounded by walls and/or is not a rectangle.\n"));
	if (!valid_chars_check(game))
		return (error("The map is missing and/or contains invalid/too many characters.\n"));
	set_start_and_exit(game);
	tokens = game->collectibles + game->exit;
	printf("the number of tokens: %d\n", tokens);
	if (!init_valid_path(game))
		return(error("Error while copying the 2D map in the temp grid.\n"));
	if (!map_path_finder(game, game->start_p.y, game->start_p.x, &tokens))
		return (error("No valid path found in the map .ber file. The player cannot exit the game.\n"));
	return (1);
}


	// int	i;
	// i = 0;
	// while (game->flood_grid[i])
	// 	printf("%s\n", game->flood_grid[i++]);