/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/17 16:39:56 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// return type static int of gewone int???

int	count_columns(char *map_row)
{
	int	i;
	
	// check of onderstande statement wel noodzakelijk is
	if (!map_row)
		return (0);
		
	i = 0;
	// count the number of chars of the first line until \n 
	while(map_row[i] && map_row[i] != '\n')
		i++;
	return (i);
}

// this function is to copy the address of the returned new_lines from gnl 
// from the file pointed by fd in the 2D array called "map"
// so that I can check for errors later
// line has the mem address of the first line of the map txt file
// why is the return type a static int?

int	allocate_rows(t_map *game, char *line)
{
	char	**temp;
	int		i;
	
	// alocate memory for the rows in the map of the game
	if (!line)
		return (0);
	
	// each \n in txt is represented by the game.rows var
	game->rows++;
	
	// allocate mem for each \n from the txt file via tmp 
	temp = (char **)malloc((game->rows + 1) * sizeof(char *));
	if (!temp)
		return (error("Allocation temp array failure."));

	// add null terminator to last block of mem
	temp[game->rows] = NULL;

	// copy first what has already been stored in map
	i = 0;
	
	while (i < (game->rows - 1))
	{
		temp[i] = game->map[i];
		i++;
	} 
	temp[i] = line;

	// check if game->map already had an address assigned;
	// if not --> free so that the newly allocated address can be assigned
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_map *game, char *map_file)
{
	char	*line;
	
	game->map = NULL;
	game->fd = open(map_file, O_RDONLY);
	if (game->fd < 0)
		return (error("File opening failure.")); // later aanpassen?
	game->rows = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break;
		allocate_rows(game, line);
	}
	printf("number of rows/lines in the map: %d\n", game->rows);

	// close the file
	close(game->fd);

	// count the number of columns
	game->columns = 0;
	game->columns = count_columns(game->map[0]);
	printf("number of columns in the map: %d\n", game->columns);
	return (1);
}
