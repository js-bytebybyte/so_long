/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/11 17:08:14 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
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
	void 	*wall;
	void 	*floor;
	void	*player_img;
	void	*exit_img;
	void	*collectible_img;
}	t_map;


int valid_file(int argc, char *file);
int valid_file_extension(char *file_name, char *file_extension);
int map_reading(t_map *game, char *map_file);
int ft_wall_check(t_map *game);
int ft_char_check(t_map *game);
void set_start_and_exit(t_map *game);

void init_game_images(t_map *game);
void adding_in_graphics(t_map *game);

#endif	