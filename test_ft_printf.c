/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:30:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/27 16:11:51 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	character = 'w';
	char	*string = "Soy un string";
	int		number = 56;

	printf("Esto es un caracter: %c\n", character);
	printf("Esto es un string: %s\n", string);
	printf("Esto es un número decimal: %d\n", number);
	printf("Esto es un entero en base 10: %i\n", number);

	ft_printf("Hola %d %d %s %c\n", 42, 56, "siguiente", 'h');
	return (0);
}
