/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/31 15:56:41 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*----------------------- Additional libraries ------------------------------*/

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

/*----------------------- Key controls macro ------------------------------*/

# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53

/*-------------------------------- Graphics ------------------------------*/

# define IMG_SIZE 32

/*----------------------- Structure for game map -------------------------*/

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
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
	char	**flood_grid;
	int		fd;
	int		rows;
	int		columns;
	int		player;
	int		exit;
	int		collectibles;
	int		moves;

	t_point	player_p;
	t_point	exit_p;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*exit_img;
	void	*collectible_img;
	void	*background_img;
	void	*player_img;

}	t_map;

/*----------------------- Functions ------------------------------*/

// game utils
int		error(char *message);
int		terminate_game(t_map *game);
void	ft_free_array(char **array);

// 2D map array initialization and map file check functions
int		map_init_checks(t_map *game, char *map_file);
int		map_reading(t_map *game, char *map_file);
int		init_flood_grid(t_map *game);
int		map_path_finder(t_map *game, int current_y, int current_x, int *tokens);

// graphics
int		init_graphics(t_map *game);
void	init_background(t_map *game);
void	init_game_images(t_map *game);
void	display_graphics(t_map *game);

// hooks functions
int		key_controls(int keycode, t_map *game);
int		update(t_map *game);

#endif