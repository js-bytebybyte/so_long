/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:22:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/30 16:44:37 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	error(char *message)
{
	printf("\033[0;31m" "Error: %s\n" "\033[0m", message);
	return (0);
}

int	valid_file_extension(char *file_name, char *file_extension)
{
	int	i;
	int	j;

	if (!file_name || !file_extension)
		return (0);
	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	j = 0;
	while (file_extension[j] && file_name[i + j] == file_extension[j])
		j++;
	if (j == 4 && file_name[i + j] == '\0')
		return (1);
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
	if (!game)
		return (0);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	if (game->map)
		ft_free_array(game->map);
	if (game->flood_grid)
		ft_free_array(game->flood_grid);
	exit(0);
}
