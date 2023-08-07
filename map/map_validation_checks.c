/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/07 17:38:49 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* functions to check the conditions to be met for a valid map */

// 1. check if file is valid

int	valid_file(int argc, char *file)
{
	// the number of arguments is 1
	if (argc == 1)
		printf("No arguments were passed.");
	
	// the number of arguments is higher than 2; so too many arguments
	if (argc > 2)
		printf("Please only provide 1 map file.");
	
	// I need to check if the file has the rigth extension
	if (!ft_string_chr(file, ".ber")

	return (0);
}

// 2. check the walls 

int	ft_wall_check(t_map *game)
{
	int	i;
	int map_colums;
	int	map_rows;

	// check if the first row and the last row of the map contains only '1's 
	// this is the horizontal wall check
	i = 0;
	map_colums = game->columns;
	while (i < map_colums)
	{
		if (game->map[0][i] != '1' || game->map[map_colums - 1][i] != '1')
			return (0);
		j++;
	}
	
	// check if the fist and last column of the map contains only '1's
	// this is the vertical wall check

	map[i][0] == '1'
	map[rows - 1][]
	
	return (1)
}
