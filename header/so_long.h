/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/08 11:56:43 by jsteenpu         ###   ########.fr       */
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
}	t_map;

int ft_wall_check(t_map *game);

#endif	