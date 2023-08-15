/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/15 16:12:38 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/*----------------------- Controls for game ------------------------------*/

# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53

/*----------------------- Structure for game map ------------------------------*/

typedef struct s_size
{
	int	width;
	int	heigth;
} 	t_size;

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

	// the  images needed for the graphics
	void 	*wall;
	void 	*floor;
	void	*exit_img;
	void	*collectible_img;
	t_size	*player_img;

	// collectibles counter
	int		token;
}	t_map;



int valid_file(int argc, char *file);
int valid_file_extension(char *file_name, char *file_extension);
int map_reading(t_map *game, char *map_file);
int ft_wall_check(t_map *game);
int ft_char_check(t_map *game);
void	set_start_and_exit(t_map *game);

void	set_player_map(t_map *game);
void	init_game_images(t_map *game);
void	adding_in_graphics(t_map *game);

int	key_controls(int keycode, t_map *game);

#endif	