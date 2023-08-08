/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/08 17:13:42 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "mlx.h"
# include "get_next_line.h"
//# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


typedef struct s_map
{
	char	**map;
	int		fd;
	int		rows;
	int		columns;
	int 	player; // to count the number of players in the game - should only be one
	int 	exit; // to count the number of exits in the game - should only be one
	int 	collectibles; // the count the number of collectibles - should be at least one
}	t_map;

int ft_wall_check(t_map *game);
int ft_char_check(t_map *game);
int valid_file(int argc, char *file);
int valid_file_extension(char *file_name, char *file_extension);

#endif	