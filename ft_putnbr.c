/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:00:41 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/27 17:33:31 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

int	ft_putnbr(int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n < 0)
	{
		count++;
		write (1, "-", 1);
		if (n == -2147483648)
		{
			write (1, "2147483648", 10);
			return (11);
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
