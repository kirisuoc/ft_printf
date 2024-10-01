/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:30:38 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/01 17:35:45 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"

static int	manage_only_width(t_format *info, int number, int len,
	int fill_quantity)
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

static int	ft_putnbr_hex(size_t nbr)
{
	const char	*base;
	char		digits[32];
	int			base_len;
	int			i;
	int			printed_chars;

	printed_chars = 0;
	base = "0123456789abcdef";
	i = 0;
	base_len = 16;
	if (nbr == 0)
	{
		printed_chars += ft_putchar('0');
		return (1);
	}
	while (nbr > 0)
	{
		digits[i++] = base[nbr % 16];
		nbr = nbr / 16;
	}
	while (--i >= 0)
		printed_chars += ft_putchar(digits[i]);
	return (printed_chars);
}

int	manage_p(t_format *info, va_list *args)
{
	void				*ptr;
	unsigned long long	address;
	int					printed_chars;

	ptr = va_arg(*args, void *);
	address = (unsigned long long)ptr;
	printed_chars += ft_putchar('0');
	printed_chars += ft_putchar('x');
	printed_chars += ft_putnbr_hex(address);
	return (printed_chars);
}
