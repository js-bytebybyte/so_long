/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/08 16:55:17 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// return type static int of gewone int???

int	count_columns(char *map_row)
{
	int	i;

	i = 0;
	
	// check of onderstande statement wel noodzakelijk is
	if (!map_row)
		return (0);
		
	// count the number of chars until \n or eof
	while(map_row[i] && map_row[i] != '\n')
		i++;

	// if \n found -- add the char; 
	if (map_row[i] == '\n')
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
		return (0);
		
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

// int	map_reading(char **argv)
int	main(int argc, char **argv)
{
	t_map	game;
	char	*line;

	// for testing purposes - will be deleted
	if (argc > 2)
		return (0);
		
	// open the map pointed by argv
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0)
		return (0); // later aanpassen?
	
	// use gnl to count the number of \n in the map pointed by fd
	// with each call of gnl, count the number of rows 
	while (1)
	{
		line = get_next_line(game.fd);
		if (!line)
			break;
		allocate_rows(&game, line);
	}
	printf("number of rows/lines in the map: %d\n", game.rows);

	// close the file
	close(game.fd);

	// count the number of 
	game.columns = count_columns(game.map[0]);
	printf("number of columns in the map: %d\n", game.columns);

	printf("Valid map: %d\n", ft_wall_check(&game));

	printf("The char check: %d\n", ft_char_check(&game));
	return (1); 
}
