/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:38:16 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/18 17:14:41 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
/*
** Put a string in the window.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	int  x			the x location;
** @param	int  y			the y location;
** @param	int  color		the font color;
** @param	char *string	the text to write;
** @return	int				has no return value (bc).
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
*/


// void	display_moves(t_map	*game)
// {
// 	char	*s; // the text to write 
	
// 	s = ft_itoa(game->moves);
// 	mlx_string_put(game->mlx_ptr, game->win_ptr, IMG_SIZE / 4, IMG_SIZE / 4, -1, s);
// 	free(s);
// }