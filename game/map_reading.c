/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/30 15:54:01 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	count_columns(char *map_row)
{
	int	i;

	if (!map_row)
		return (0);
	i = 0;
	while (map_row[i] && map_row[i] != '\n')
		i++;
	return (i);
}

static int	allocate_rows(t_map *game, char *line)
{
	char	**temp;
	int		i;

	if (!line || !game)
		return (0);
	game->rows++;
	temp = (char **)malloc((game->rows + 1) * sizeof(char *));
	if (!temp)
		return (0);
	temp[game->rows] = 0;
	i = 0;
	while (i < (game->rows - 1))
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_map *game, char *map_file)
{
	char	*line;

	game->fd = open(map_file, O_RDONLY);
	if (game->fd < 0) 
		return (error("Failure to open the map file."));
	line = get_next_line(game->fd);
	while (line)
	{
		allocate_rows(game, line);
		line = get_next_line(game->fd);
	}
	if (!line && !game->map)
		return (0);
	close(game->fd);
	game->columns = count_columns(game->map[0]);
	return (1);
}
