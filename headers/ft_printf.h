/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:49:04 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/06/02 10:41:18 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_format_c(int c);
int	ft_format_s(char *s);
int	ft_format_p(unsigned long ptr_value);
int	ft_format_i_d(int nbr);
int	ft_format_u(unsigned int nbr);
int	ft_format_x(unsigned int nbr, char specifier);
int	ft_printf(const char *format, ...);

#endif
