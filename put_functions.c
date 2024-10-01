/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:08:55 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/01 17:49:25 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

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
