/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:30:38 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/01 16:34:42 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"

static int	manage_only_width(t_format *info, int number, int len, int fill_quantity)
{
	int	printed_chars;

	printed_chars = 0;
	while (fill_quantity-- > 0)
	{
		write(1, " ", 1);
		printed_chars++;
	}
	printed_chars += ft_putnbr(number);
	return (printed_chars);
}

static int	manage_flags_d(t_format *info, int number, int len)
{
	int		printed_chars;
	int		fill_quantity;
	char	flag_to_write;

	fill_quantity = 0;
	printed_chars = 0;
	if (info->min_width > len)
		fill_quantity = info->min_width - len;
	while (fill_quantity-- > 1)
		printed_chars +=  ft_putchar(' ');
	flag_to_write = '\0';
	if (info->flag_plus && number > 0)
		flag_to_write = '+';
	else if (info->flag_space && number > 0)
		flag_to_write = ' ';
	else if (number < 0)
		flag_to_write = '-';
	if (flag_to_write)
	{
		printed_chars += ft_putchar(flag_to_write);
		printed_chars += ft_putnbr(number);
	}
	else
		printed_chars += ft_putnbr(number);
	if (info->min_width && !info->flag_plus && !info->flag_space)
		printed_chars += manage_only_width(info, number, len, fill_quantity);
	return (printed_chars);
}

int	manage_d(t_format *info, va_list *args)
{
	int	printed_chars;
	int	number;
	int	len_number;

	printed_chars = 0;
	number = va_arg(*args, int);
	len_number = get_number_length(number);

	printed_chars += manage_flags_d(info, number, len_number);

	return (printed_chars);
}
