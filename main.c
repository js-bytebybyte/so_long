/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:53:27 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/28 14:04:20 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

typedef struct s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_program;


void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	deal_key(int key, void *param)
{
	ft_putchar('X');
	//put pixel on display every time a key is touchec?
	mlx_pixel_put();
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	//initialize the connection between my software and the display
	mlx_ptr = mlx_init();
	
	// manages windows
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 19");

	// draws a defined pixel in the window win_ptr using coordinates
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);

	// deal_key is the function pointer you want to call when an event occurs
	// void *param > the address will be passed to deal_key; 
	// should be used to store the parameters it might need
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	
	// handles keyboard or mouse events
	// inifinite loop that waits for an event
	mlx_loop(mlx_ptr);
	
	return (0); 	
}