/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:30:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/28 14:41:54 by erikcousill      ###   ########.fr       */
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
	int		countletters = 0;

/* 	printf("Esto es un caracter: %c\n", character);
	printf("Esto es un string: %s\n", string);
	printf("Esto es un número decimal: %d\n", number);
	printf("Esto es un entero en base 10: %i\n", number); */

	/* countletters = ft_printf("Hola, %-s %i %c\n", string, number, character); */
	/* ft_printf("%d\n", countletters); */
	ft_printf("%010d\n", 42);  // "42        " (justificado a la izquierda)


	return (0);
}
