/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/25 17:36:30 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*----------------------- Additional libraries ------------------------------*/

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/*----------------------- Key controls macro ------------------------------*/

# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53

/*----------------------- Graphics ------------------------------*/

//# define ANIMATION_FRAMES 10
# define IMG_SIZE 32


/*----------------------- Structure for game map -------------------------*/

typedef struct s_size
{
	int	width;
	int	heigth;
} 	t_size;

typedef struct s_img
{
	//void	*win;
	void	*img_ptr;
	char	*address;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
	int		color;
}		t_img;

typedef struct s_map
{
	char	**map;
	char	**valid_path;
	int		fd;
	int		rows;
	int		columns;
	int 	player; // to count the number of players in the game - should only be one
	int 	exit; // to count the number of exits in the game - should only be one
	int 	collectibles; // the count the number of collectibles - should be at least one
	int		moves; // to count the number of moves of the player
	
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;

	void 	*mlx_ptr;
	void 	*win_ptr;

	// the  images needed for the graphics
	void 	*wall;
	//void 	*floor;
	void	*exit_img;
	void	*collectible_img;
	void	*background_img;
	t_size	*player_img;

}	t_map;

/*----------------------- Functions ------------------------------*/


// game utils
int	error(char *message);
int	terminate_game(t_map *game);
int	valid_file_extension(char *file_name, char *file_extension);


// map init and checks functions
int	map_init_checks(t_map *game, int argc, char *map_file);
int	map_reading(t_map *game, char *map_file);
int init_valid_path(t_map *game);
int map_path_finder(t_map *game, int current_y, int current_x);


// graphics
int	init_graphics(t_map *game);
void	init_background(t_map *game);
void	init_game_images(t_map *game);
void	adding_in_graphics(t_map *game);


// hooks functions
int	key_controls(int keycode, t_map *game);
int	update(t_map *game);

#endif	