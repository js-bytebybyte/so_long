/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:27 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/16 12:17:25 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	move_up(char **map, int y, int x, int token)
{
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C') // the tile above is just the floor
	{
		if (map[y - 1][x] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		y -= 1;				   // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y - 1][x] == 'E')
		return (0);
	return (y);
}

int move_down(char **map, int x, int y, int token)
{
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C') // the tile above is just the floor
	{
		if (map[y + 1][x] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		y += 1;			 // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y + 1][x] == 'E')
		return (0);
	return (y);
}

int move_left(char **map, int y, int x, int token)
{
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		if (map[y][x - 1] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		x -= 1;			 // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y][x - 1] == 'E')
		return (0);
	return (x);
}

int move_right(char **map, int y, int x, int token)
{
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		if (map[y][x + 1] == 'C')
		{
			printf("Yummy, another candy in my tummy!\n");
			token++;
		}
		map[y][x] = '0'; // set the current position as floor
		x += 1;			 // go up along the vertical axis
		map[y][x] = 'P'; // change the new start position value to P so that the player can be potioned there
	}
	else if (map[y][x + 1] == 'E')
		return (0);
	return (x);
}