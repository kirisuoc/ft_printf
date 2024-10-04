/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:29:45 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/04 17:09:13 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	manage_only_width(int number, int fill_quantity)
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

int	manage_flags_d(t_format *info, int number, int len)
{
	int		printed_chars;
	int		fill_quantity;
	char	flag_to_write;

	fill_quantity = 0;
	printed_chars = 0;
	if (info->min_width > len)
		fill_quantity = info->min_width - len;
	while (fill_quantity-- > 1)
		printed_chars += ft_putchar(' ');
	flag_to_write = '\0';
	if (info->flag_plus && number > 0)
		flag_to_write = '+';
	else if (info->flag_space && number > 0)
		flag_to_write = ' ';
	else if (number < 0)
		flag_to_write = '-';
	if (flag_to_write)
		printed_chars += ft_putchar(flag_to_write) + ft_putnbr(number);
	else
		printed_chars += ft_putnbr(number);
	if (info->min_width && !info->flag_plus && !info->flag_space)
		printed_chars += manage_only_width(number, fill_quantity);
	return (printed_chars);
}

int	get_number_length(int number)
{
	int	len;

	if (number <= 0)
		len = 1;
	else
		len = 0;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}
