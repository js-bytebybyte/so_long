/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:39:39 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/08/08 11:01:07 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // needs to be adjusted??

int	valid_file_extension(char *file_name, char	*file_extension)
{
	int	i;
	int	j;

	if (!file_name || !file_extension)
		return (0);
	i = 0;
	while (file_name[i])
		i++;
	j = 0;
	while (file_extension[j] && file_name[i - 4] == file_extension[j])
	{
		i++;
		j++;
	}
	if (j == 4)
		return (1); // this is a match - the file has the right extension
	return (0); // no match - the file doesn't have the correct extension
}
