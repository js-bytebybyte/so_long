/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hooks_escape_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:24:12 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/01 11:34:50 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <X11/keysym.h>
#include "mlx.h"
#include <stdio.h>

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

int	handle_no_event(void *data)
{
    /* This function needs to exist, but it is useless for the moment */
    return (0);
}

int	handle_input(int keysym, t_data *data)
{
	// if left key is released, go left
	// how do i change the position of my image on screen?
    if (keysym == 123) // KEY LEFT RELEASE ?
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (keysym == 124) // KEY RIGHT RELEASE ?
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (keysym == 125) // KEY DOWN RELEASE ?
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (keysym == 126) // KEY UP RELEASE ?
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}

int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "My first window!");

    /* Setup hooks */
	
	// hook that is triggered when there is no event processed
	// useful to continuesly draw things on the screen -- not really needed in our example
	// we need it because without it, the loop will have never ended 
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	
	// to register any X event via the handle_input function 
    mlx_key_hook(data.win_ptr, &handle_input, &data);

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    //mlx_destroy_display(data.mlx_ptr);

	return (0);
}