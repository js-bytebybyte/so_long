/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:22:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/29 13:19:52 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	error(char *message)
{
	printf("\033[0;31m" " Error: %s\n" "\033[0m", message);
	return (0);
}

int	terminate_game(t_map *game)
{
	int		i;
	
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	i = 0;
	if (game->map[i])
	{
		while (i < game->rows)
		{	
			free(game->map[i]);
			i++;
		}
	}
	free(game->map);
	i = 0;
	if (game->flood_grid[i])
	{
		while (i < game->rows)
		{	
			free(game->flood_grid[i]);
			i++;
		}
	}
	free(game->flood_grid);
	exit(0);
}
int	valid_file_extension(char *file_name, char	*file_extension)
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
		return (1); // this is a match - the file has the right extension
	return (0); // no match - the file doesn't have the correct extension
}