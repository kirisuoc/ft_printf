/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:57:10 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/28 14:41:09 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>

/*	__ Bonus 1 __
	- : Justificación a la izquierda. El valor se imprime alineado a la izquierda.
	0 : Relleno con ceros en lugar de espacios.
	. : Indica la precisión para números decimales o la cantidad de dígitos que se deben
		imprimir para números enteros.

	__ Bonus 2 __
	# : Usa un formato alternativo
		* Para hexadecimales (%x, %X) se añade un prefijo 0x o 0X.
	+ : Siempre imprime el signo + para números positivos (y - para negativos)
   ' ': Deja un espacio en lugar del signo para números positivos (si no se usa el flag +)
*/

// %c Imprime un solo caracter
// %s Imprime una string (como se define por defecto en C)
// %p El puntero void * (dado como argumento se imprime en formato hexadecimal)
// %d Imprime un número decimal (base 10)
// %i Imprime un entero en base 10
// %u Imprime un número decimal (base 10) sin signo
// %x Imprime un número hexadecimal (base 16) en minúsculas
// %X Imprime un número hexadecimal (base 16) en mayúsculas
// %% para imprimir el símbolo del porcentaje

int	manage_c(char character)
{
	return (ft_putchar(character));
}

int	manage_s(char *string)
{
	return (ft_putstr(string));
}

int	manage_d(int number)
{
	return (ft_putnbr(number));
}

void manage_flags_negative_sign(char *format)
{
	int	i;

	i = 1;
	while (format[i] != 'd')
	{

	}
	printf("ha llegado aqui\n");
}
int	count_digits(int n)
{
	int		num_digits;

	if (n == 0)
		return (1);
	num_digits = 0;
	while (n > 0)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

void	fill_width(char fill, int quantity)
{
	if (fill == '-')
		while (quantity-- > 0)
			write(1, " ", 1);
	else if (fill == '0')
		while (quantity-- > 0)
			write(1, "0", 1);
}

int	manage_conv_d(char *format, int number)
{
	int i;
	int	width;
	int	fill_quantity;

	i = 0;
	if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(number));
	else if (format[i] == '-')
	{
		i++;
		width = ft_atoi(format + i);
		fill_quantity = width - ft_putnbr(number);
		while (fill_quantity-- > 0)
			write(1, " ", 1);
	}
	else if (format[i] == '0')
	{
		width = ft_atoi(format + i);
		fill_quantity = width - count_digits(number);
		while (fill_quantity-- > 0)
			write(1, "0", 1);
		ft_putnbr(number);
	}
	else if (ft_isdigit(format[i]))
	{
		width = ft_atoi(format + i);
		fill_quantity = width - count_digits(number);
		while (fill_quantity-- > 0)
			write(1, " ", 1);
		ft_putnbr(number);
	}
	return (width);
}


int	ft_printf(char const *format, ...)
{
	va_list		args;		// Define una variable que almacenará los argumentos pasados
	va_start(args, format);	// Inicializa el objeto 'va_list' para acceder a los argumentos
							// va_arg recupera los argumentos uno por uno, especificando el tipo
							// va_end limpia la variable va_list
	int			number;
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += manage_conv_d((char *)format + i, va_arg(args, int));
			while (format[i] && format[i] != 'd' && format[i] != 'i')
				i++;
/* 			if (format[i] == 'c')
				count += manage_c(va_arg(args, int));
			if (format[i] == 's')
				count += manage_s(va_arg(args, char *));
			if (format[i] == 'd' || format[i] == 'i')
				count += manage_d(va_arg(args, int));
			if (format[i] == 'p')
			{
				
			} */
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}
