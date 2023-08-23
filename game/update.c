/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:38:16 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/23 10:41:31 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	display_moves(t_map	*game)
{
	char	*s; // the text to write 
	
	s = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, IMG_SIZE / 4, IMG_SIZE / 4, -1, s);
	free(s);
}

int	update(t_map *game)
{
	display_moves(game);
	return (1);	
}