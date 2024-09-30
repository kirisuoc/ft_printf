/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:30:38 by erikcousill       #+#    #+#             */
/*   Updated: 2024/09/30 19:53:16 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"

int	manage_c(t_format *info, va_list *args)
{
	int	printed_chars;

	printed_chars = 0;
	if (info->flag_minus && info->min_width)
	{
		printed_chars += ft_putchar(va_arg(*args, int));
		while (info->min_width > 1)
		{
			printed_chars += ft_putchar(' ');
			info->min_width--;
		}
	}
	else if (info->min_width)
	{
		while (info->min_width > 1)
		{
			printed_chars += ft_putchar(' ');
			info->min_width--;
		}
		printed_chars += ft_putchar(va_arg(*args, int));
	}
	else
		printed_chars += ft_putchar(va_arg(*args, int));
	return (printed_chars);
}

/* int	manage_d(t_format *info, va_list *args)
{
	int	printed_chars;
	int	fill_quantity;
	int	len_number;
	int	number;

	printed_chars = 0;
	number = va_arg(*args, int);
	len_number = ft_strlen(ft_itoa(number));
	fill_quantity = 0;

	if (info->min_width > len_number)
		fill_quantity = info->min_width - len_number;
	if (info->flag_minus && info->min_width)
	{
		if (number < 0)
			write(1, "-", 1);
		ft_putnbr(number);
		while (fill_quantity-- > 0)
			write(1, " ", 1);
		fill_quantity += info->min_width;
		return (info->min_width);
	}
	else if (info->flag_zero && info->min_width)
	{
		if (number < 0)
			write(1, "-", 1);
		while (fill_quantity-- > 0)
			write(1, "0", 1);
		fill_quantity += ft_putnbr(number);
		return (info->min_width);
	}
	else if (info->min_width)
	{
		while (fill_quantity-- > 0)
			write(1, " ", 1);
		fill_quantity += ft_putnbr(number);
		return (len_number + fill_quantity);
	}
	else
		return (ft_putnbr(number));
}
*/

int	manage_flags_d(t_format *info, va_list *args)
{
	int	printed_chars;
	int	fill_quantity;
	int	len_number;
	int	number;

	printed_chars = 0;
	number = va_arg(*args, int);
	len_number = ft_strlen(ft_itoa(number));
	fill_quantity = 0;

	if (info->min_width > len_number)
		fill_quantity = info->min_width - len_number;
	if (info->flag_minus && info->min_width)
	{
		if (number < 0)
			write(1, "-", 1);
		ft_putnbr(number);
		while (fill_quantity-- > 0)
			write(1, " ", 1);
		fill_quantity += info->min_width;
		return (info->min_width);
	}
	else if (info->flag_zero && info->min_width)
	{
		if (number < 0)
			write(1, "-", 1);
		while (fill_quantity-- > 0)
			write(1, "0", 1);
		fill_quantity += ft_putnbr(number);
		return (info->min_width);
	}
	else
	{
		return (0);
	}
}

int	manage_flag_minus(t_format *info, va_list *args, int number)
{

}

int	manage_flag_zero(t_format *info, va_list *args, int number)

int	manage_d_2(t_format *info, va_list *args, int number)
{
	int	printed_chars;
	int	fill_quantity;
	int	len_number;
	int	number;

	if (info->min_width && info->flag_zero == 0 && info->flag_zero == 0)
	{
		while (fill_quantity-- > 0)
			write(1, " ", 1);
		fill_quantity += ft_putnbr(number);
		return (len_number + fill_quantity);
	}
	else
	{
		return (ft_putnbr(number));
	}
	/* 	else if (info->precision)
	{

	} */
}
int	manage_d(t_format *info, va_list *args)
{
	int	printed_chars;

	printed_chars += manage_flags_d(info, args);
	printed_chars += manage_d_2(info, args);

	return (printed_chars);
}
