/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:14 by jolandestee       #+#    #+#             */
/*   Updated: 2023/08/30 16:38:38 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	init_flood_grid(t_map *game)
{
	int	i;
	int	j;

	if (!game)
		return (0);
	game->flood_grid = malloc(sizeof(char *) * (game->rows + 1)); 
	if (!game->flood_grid)
		return (0);
	i = 0; 
	while (i < game->rows)
	{
		game->flood_grid[i] = malloc(sizeof(char) * (game->columns + 1));
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

int	map_path_finder(t_map *game, int current_y, int current_x, int *tokens)
{
	if (!game || !tokens || !current_y || !current_x)
		return (0);
	if (current_y < 0 || current_y >= game->rows || 
		current_x < 0 || current_x >= game->columns) 
		return (0);
	if (game->flood_grid[current_y][current_x] == '1' || 
		game->flood_grid[current_y][current_x] == 'F')
		return (0);
	if (game->flood_grid[current_y][current_x] == 'C' || 
		game->flood_grid[current_y][current_x] == 'E' )
		(*tokens)--;
	if (*tokens == 0)
		return (1);
	game->flood_grid[current_y][current_x] = 'F';
	if (map_path_finder(game, current_y - 1, current_x, tokens))
		return (1);
	if (map_path_finder(game, current_y + 1, current_x, tokens)) 
		return (1);
	if (map_path_finder(game, current_y, current_x - 1, tokens))
		return (1);
	if (map_path_finder(game, current_y, current_x + 1, tokens))
		return (1);
	return (0);
}
