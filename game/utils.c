/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:22:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/01 10:36:40 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	error(char *message)
{
	ft_printf("\033[0;31m" "Error: %s\n" "\033[0m", message);
	return (0);
}

void	ft_free_array(char	**array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	if (array[i])
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	free(array);
}

int	terminate_game(t_map *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	ft_free_array(game->map);
	ft_free_array(game->flood_grid);
	exit(EXIT_SUCCESS);
}
