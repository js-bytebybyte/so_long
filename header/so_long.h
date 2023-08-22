/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/22 13:12:53 by jsteenpu         ###   ########.fr       */
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

# define IMG_SIZE 32
/*----------------------- Structure for game map -------------------------*/

typedef struct s_size
{
	int	width;
	int	heigth;
} 	t_size;


typedef struct s_img
{
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_map
{
	char	**map;
	int		fd;
	int		rows;
	int		columns;
	int 	player; // to count the number of players in the game - should only be one
	int 	exit; // to count the number of exits in the game - should only be one
	int 	collectibles; // the count the number of collectibles - should be at least one
	int		moves;
	
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;

	void 	*mlx_ptr;
	void 	*win_ptr;

	// the  images needed for the graphics
	void 	*wall;
	void 	*floor;
	void	*exit_img;
	void	*collectible_img;
	void	*background_img;
	t_size	*player_img;

}	t_map;

/*----------------------- Functions ------------------------------*/

int	terminate_game(t_map *game);
int valid_file_extension(char *file_name, char *file_extension);
int	map_init_checks(t_map *game, int argc, char *map_file);
int map_reading(t_map *game, char *map_file);

void	init_background(t_map *game);
void	init_game_images(t_map *game);
void	adding_in_graphics(t_map *game);

//char	*ft_itoa(int n);
//void	display_moves(t_map	*game);

int	key_controls(int keycode, t_map *game);

int	error(char *message);

#endif	