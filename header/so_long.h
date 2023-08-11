/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/11 12:51:40 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
//# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/*----------------------- Structure for game map ------------------------------*/


typedef struct s_map
{
	char	**map;
	int		fd;
	int		rows;
	int		columns;
	int 	player; // to count the number of players in the game - should only be one
	int 	exit; // to count the number of exits in the game - should only be one
	int 	collectibles; // the count the number of collectibles - should be at least one
	
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	//int		directions[4][2];

	void 	*mlx_ptr;
	void 	*win_ptr;
}	t_map;

typedef	struct s_graphics
{
	void	*player;
	void	*exit;
	void	*wall;
	void	*floor;
	void 	*collectibles;
	
} t_graphics;

// how to write pixels to image
// we need to get the mem address on which we will mutate the bytes acc
// to retrieve the address :

typedef struct s_data
{
	void *img;
	char *address;
	int bytes_per_pixel;
	int line_length;
	int endian;
} t_data;

/* Initialize the data needed to check if the map is valid */
// t_map	*ft_initialize_map_var(t_map *game)
// {
// 	game->map = NULL;
// 	game->fd = 0;
// 	game->rows = 0;
// 	game->columns = 0;
// 	game->player = 0;
// 	game->exit = 0;
// 	game->collectibles = 0;
// 	game->start_x = 0;
// 	game->start_y = 0;
// 	game->exit_x = 0;
// 	game->exit_y = 0;
// 	// game->directions[4][2] =
// 	// {
// 	// 	{1, 0}, // UP
// 	// 	{-1, 0}, // DOWN
// 	// 	{0, 1}, // RIGHT
// 	// 	{0, -1} // LEFT
// 	// };
// 	return (game);
// }

int valid_file(int argc, char *file);
int valid_file_extension(char *file_name, char *file_extension);
int map_reading(t_map *game, char *map_file);
int ft_wall_check(t_map *game);
int ft_char_check(t_map *game);
void set_start_and_exit(t_map *game);

#endif	