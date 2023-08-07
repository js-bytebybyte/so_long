/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:54:49 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/04 14:59:02 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


// to remember
// if a file is empty; meaning \0 is the only char 
// read will return 1 (so 1 char was read);
int	main(void)
{
	int		fd;
	int		chars_read;
	char	c;

	fd = open("empty.txt", O_RDONLY);
	chars_read = read(fd, &c, 1);
	printf("chars_read: %d\n", chars_read);
	return (0);
}