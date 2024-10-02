/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:30:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/02 13:28:54 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char			character = 'w';
	char			*string = "Soy un string";
	int				number = 568;
	int				countletters = 0;
	unsigned int	unumber = 3147483648;
	int				*ptr = &number;
	unsigned int	hexnumber = 66666;

/* 	printf("Esto es un caracter: %c\n", character);
	printf("Esto es un string: %s\n", string);
	printf("Esto es un número decimal: %d\n", number);
	printf("Esto es un entero en base 10: %i\n", number);

	countletters = ft_printf("Hola, %s %010d %c\n", string, number, character);
	printf("Hola, %s %i %c\n", string, number, character); */
/*
	int	countletters1 = ft_printf("%015d %-5d %019i %18d %-12i %%\n", -2147483647, -6546, 99, 1234553, -543543534);
	printf("%.10d\n", -2138);
	int	countletters2 = printf("%015d %-5d %019i %18d %-12i %%\n", -2147483647, -6546, 99, 1234553, -543543534);
 */
/* 	int countletters1 = ft_printf("%d   %+ d %d\n", -54325, 2147483, 4);
	int countletters2 =    printf("%d   %+ d %d\n", -54325, 2147483, 4); */

	int countletters1 = ft_printf("%p %s %+10d %u %X%%%%\n", (void *)ptr, string, number, unumber, hexnumber);
	int countletters2 =    printf("%p %s %+10d %u %X%%%%\n", (void *)ptr, string, number, unumber, hexnumber);

	printf("%d\n", countletters1);
	printf("%d\n", countletters2);
	return (0);
}
