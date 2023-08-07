/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:03:53 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/04 16:08:58 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------- Conditions to check ----------------------------------*/

/*

1. The map must contain: 1 start 1 exit, at least 1 collectible > 1 
2. The map must be rectangular
3. The map must be closed/surrended by walls
4. check  if there is a valid path
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

int	line_count(char	*file)
{
	int		fd;
	int		lines;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = 0;
	// issue: why is it printing the \0 char twice???
	while (read(fd, &c, 1) == 1)
	{
		printf("%c", c);
		if (c == '\n')// c == '\0')
			lines++;
	}
	printf("\nlines: %d\n", lines);
	return (lines);
}


int	main(void)
{
	//char	**map;
	char	*filename = "empty.txt";
	int		rows;

	// 1 - count the number of line in the map
	rows = line_count(filename);
	if (rows < 2)
		return (-1);
	printf("rows: %d\n", rows);

	
	// allocate memory to create the 2D array called map that will contain the map of the game;
	// the number of lines = the number of pointers that needs to be stored in map
	// +1 for the null terminator
	
	map = (char **)malloc((rows + 1) * sizeof(char *)); 
	if (!map)
		return (-1);
	
	// // fill the 2D array = map
	// fd = open("check.txt", O_RDONLY);
	// i = 0;
	// while (i < rows)
	// {
	// 	map[i] = malloc((col_counter) * sizeof(char));
	// 	if (!map[i])
	// 		return (-1);
	// 	j = 0;
	// 	while (j < col_counter) // 14
	// 	{
	// 		read(fd, &c, 1);
	// 		map[i][j] = c;
	// 		j++;
	// 	}
	// 	map[i][j] = '\0';
	// 	j++;
	// }
	// map[i] = 0;

	// int i = 0;
	// while (map[i] != NULL)
	// 	printf("%s", map[i++]);
		
	return (0);
}
