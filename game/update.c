/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:38:16 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/31 15:11:55 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	display_moves(t_map	*game)
{
	char	*s; 

	s = ft_itoa(game->moves);
	if (!s)
		return ;
	mlx_string_put(game->mlx_ptr, game->win_ptr, 
		IMG_SIZE / 4, IMG_SIZE / 4, -1, s);
	free(s);
}

int	update(t_map *game)
{
	display_moves(game);
	return (0);
}
