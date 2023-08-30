/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/30 16:23:05 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/* 1. check if the map file is provided and correct */ 

static int	valid_file(int argc, char *file)
{
	if (!argc || !file)
		return (error("Valid file failure."));
	if (argc > 2)
		return (error("Please provide just one map.ber file."));
	if (!valid_file_extension(file, ".ber"))
		return (error("Incorrect file extension. Please provide a .ber file."));
	return (1);
}

/* 2. The map must be closed/surrounded by walls. */

static int	walls_check(t_map *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* 3. The map can only be composed of 5 characters */

static int	valid_chars_check(t_map *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns) 
		{
			if (!ft_strchr("10CPE", game->map[i][j]))
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
	if (game->player != 1 || game->exit != 1 || game->collectibles < 1)
		return (0);
	return (1);
}

/* if all OK, look for the player's start and the exit position */

static void	set_start_and_exit(t_map *game)
{
	int	x; 
	int	y; 

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_p.x = x;
				game->player_p.y = y;
			}
			if (game->map[y][x] == 'E')
			{
				game->exit_p.x = x;
				game->exit_p.y = y;
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
		return (error("Issue with map walls.\n"));
	if (!valid_chars_check(game))
		return (error("Missing and/or invalid/too many characters.\n"));
	set_start_and_exit(game);
	tokens = game->collectibles + game->exit;
	if (!init_valid_path(game))
		return (error("Issue with the creation of the flood grid.\n"));
	if (!map_path_finder(game, game->player_p.y, game->player_p.x, &tokens))
		return (error("No valid path found.\n"));
	return (1);
}
