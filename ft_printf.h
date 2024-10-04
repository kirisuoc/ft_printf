/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:59 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/04 16:49:23 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_format
{
	int		flag_plus;
	int		flag_hash;
	int		flag_space;
	int		min_width;
	char	specifier;
}			t_format;

int		ft_printf(char const *format, ...);
void	parse_format(char **format, t_format *info);

// put_functions
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_hex(size_t nbr, const char *base);
int		get_number_length(int number);

// aux_functions
int		manage_only_width(int number, int fill_quantity);
int		manage_flags_d(t_format *info, int number, int len);
int		get_number_length(int number);

// manage_specifiers
int		manage_d(t_format *info, va_list *args);
int		manage_p(unsigned long ptr);
int		manage_x(t_format *info, va_list *args);

#endif
