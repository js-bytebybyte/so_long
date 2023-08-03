/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:03:53 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/03 17:10:00 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------- Conditions to check ----------------------------------*/

/*

1. The map must contain: 1 start 1 exit, at least 1 collectible > 1 
2. The map must be rectangular
3. The map must be closed/surrended by walls
4. Check if there is a valid path
5. You must parse through any kind of map
6. If any misconfiguration is encountered, program must exit in a clean way 
and return 'Error\n' with explicit error message of your choice

*/

/* 
- open the file
- check for errors
- read the file, character by character,
- if new_line is encountered, increase counter
- store each read character in the 2-D array called map 
- NULL terminate each 1-D array 
- print the map
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MAP_ROWS 100
#define MAX_MAP_COLS 100

int	main(void)
{
	char	**map;
	int		rows;
	int		columns;
	int		rows_counter;
	int		col_counter;
	int		fd;
	char	c;

	// open the file
	fd = open("map.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
		
	// read the file and keep track of the number of lines in the file
	rows_counter = 0;
	while (read(fd, &c, 1) == 1)
	{	
		//printf("%c\n", c);
		if (c == '\n')
			rows_counter++;
	}
	rows_counter++; // the last line of the file end with null terminator and not with \n
	fd = open("map.txt", O_RDONLY);
	col_counter = 0;
	while (c != '\n')
	{
		read(fd, &c, 1);
		col_counter++;
		printf("%c\t", c);
	}
	printf("The number of lines in the file: %d\nThe number of columns: %d\n", rows_counter, col_counter);
	
	// allocate memory to create the 2D array called map;
	// the number of lines = the size of the first array or the number of rows
	// +1 for the null terminator
	map = (char **)malloc((rows_counter + 1) * sizeof(char *)); 
	if (!map)
		return (-1);
	map[rows] = (char *)malloc((col_counter + 1) * sizeof(char));
	if (!map[rows])
		return (-1);
	printf("Ok till here\n");
	
	// fill the 2D array = map
	fd = open("map.txt", O_RDONLY);
	rows = 0;
	columns = 0;
	while (rows_counter >= 0)
	{
		read(fd, &c, 1);
		printf("Ok till here\n");
		map[rows][columns] = c;
		printf("Ok till here\n");
		if (c == '\n')
		{
			rows++;
			columns = 0;
			rows_counter--;
		}	
		columns++;
	}
	return (0);
}
