/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:50:18 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/26 16:14:52 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_free_join(char	*buffer, char *stash);
char	*ft_strjoin(char *buffer, char *stash);

void	*ft_calloc(size_t count, size_t size);

int		ft_strchr(char *stash, char c);

size_t	ft_strlen(char *s);

#endif
