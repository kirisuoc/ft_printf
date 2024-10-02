/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:08:55 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/02 13:38:17 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (!*s)
		return (0);
	write (1, s, len);
	return (len);
}

int	ft_putnbr(int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write (1, "2147483648", 11);
			return (10);
		}
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	digit = n % 10 + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned(n / 10);
	}
	digit = n % 10 + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

int	ft_putnbr_hex(size_t nbr, const char *base)
{
	char		digits[32];
	int			base_len;
	int			i;
	int			printed_chars;

	printed_chars = 0;
	i = 0;
	base_len = 16;
	if (nbr == 0)
	{
		printed_chars += ft_putchar('0');
		return (printed_chars);
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
