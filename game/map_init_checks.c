/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/18 14:21:55 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"


static int	valid_file(int argc, char *file)
{
	if (!argc || !file)
		return (error("Valid file failure."));
	if (argc == 1)
		return (error("Please provide 1 map file as argument."));
	if (argc > 2)
		return (error("Please provide just one map file."));
	if (!valid_file_extension(file, ".ber"))
		return (error("The file extension is incorrect. Please provide a .ber file."));
	return (1);
}

// 2. The map must be closed/surrounded by walls. If it’s not, the program must return

static int walls_check(t_map *game)
{
	int	i;
	int map_columns;
	int	map_rows;

	// horizontal wall check - first and last row
	i = 0;
	map_columns = game->columns; // 19
	map_rows = game->rows; // 10
	while (i < map_columns) // 13 dus van 0 tem 12; \n is op plaats 13
	{
		if (game->map[0][i] != '1' || game->map[map_rows - 1][i] != '1')
			return (0);
		i++;
	}

	// vertical wall check - first and last column
	i = 0;
	while (i < map_rows) // 5 dus van 0 tem 4; \n is op plaats 13
	{
		if (game->map[i][0] != '1' || game->map[i][map_columns - 1] != '1')
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

static int	valid_chars_check(t_map *game)
{
	int i;
	int j;
	
	i = 0;
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

static void	set_start_and_exit(t_map *game)
{
	int x; // move along the columns
	int	y; // move through the different rows

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
}

int	map_init_checks(t_map *game, int argc, char *map_file)
{
	// check if the file as argument is valid
	if (!valid_file(argc, map_file))
		return (error("Invalid map file.\n"));
		
	// read the map file + copy all the chars of the file in 2D array map
	if (!map_reading(game, map_file))
		return (error("Error while reading map.\n"));
		
	// Is the map surrounded by walls (char == '1')?
	if (!walls_check(game))
		return (error("The map file is not surrounded by walls.\n"));

	// check if the chars in map are valid
	if (!valid_chars_check(game))
		return (error("The map is missing and/or contains invalid characters.\n"));

	// retrieve the position of the player and the exit
	set_start_and_exit(game);

	return (1);
}

/*int	ft_find_valid_path(t_map *game)
{
	int		new_x;
	int		new_y;
	int		i;
	int		j;
	char	**buffer_map;
	
	if (game->start_x == game->exit_x && game->start_y == game->exit_y);
	{
		printf("Destination reached!");
		return (0);
	}
	
	// copy all elements from map in buffer 
	buffer_map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!buffer_map)
		return (0);
 	i = 0;
	while (i < game->rows)
	{
		buffer_map[i] = (char *)malloc(sizeof(char) * (game->columns + 1));
		if (!buffer_map[i])
			return (0);
		j = 0;
		while (j < game->columns) // 14
		{
			buffer_map[i][j] = game->map[i][j];
			j++;
		}
		buffer_map[i][j] = '\0';
		i++;
	}
	buffer_map[i] = 0;
	
	// mark current position as visited = 2 
	buffer_map[game->start_y][game->start_x] = 2; 
	
	// check for new position
	i = 0
	while (i < 4)
	{
		
	}

} */