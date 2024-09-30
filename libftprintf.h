/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:59 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/30 09:27:06 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>


typedef struct s_format
{
	int		flag_minus;
	int		flag_zero;
	int		min_width;
	int		precision;
	char	specifier;
}			t_format;

int		ft_printf(char const *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		manage_c(t_format *info, va_list *args);
int		manage_d(t_format *info, va_list *args);
void	parse_format(char **format, t_format *info);

#endif
