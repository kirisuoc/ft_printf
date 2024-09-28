/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:30:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/28 19:04:57 by erikcousill      ###   ########.fr       */
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

	printf("Esto es un caracter: %c\n", character);
	printf("Esto es un string: %s\n", string);
	printf("Esto es un número decimal: %d\n", number);
	printf("Esto es un entero en base 10: %i\n", number);

	countletters = ft_printf("Hola, %s %i %c\n", string, number, character);
	printf("Hola, %s %i %c\n", string, number, character);
	countletters = ft_printf("%20d\n", -21474838);
 	printf("%d\n", countletters);

	printf("%.10d\n", -2138);
	printf("%010d\n", -2138);
	return (0);
}
