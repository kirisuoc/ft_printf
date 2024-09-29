/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:57:10 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/29 13:52:46 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>

/*	__ Bonus 1 __
	- : Justificación a la izquierda. El valor se imprime
		alineado a la izquierda.
	0 : Relleno con ceros en lugar de espacios.
	. : Indica la precisión para números decimales o la cantidad de
		dígitos que se deben
		imprimir para números enteros.
*/
/*	__ Bonus 2 __
	# : Usa un formato alternativo
		* Para hexadecimales (%x, %X) se añade un prefijo 0x o 0X.
	+ : Siempre imprime el signo + para números positivos (y - para negativos)
   ' ': Deja un espacio en lugar del signo para números positivos
   		(si no se usa el flag +)
*/

// %c Imprime un solo caracter
// %s Imprime una string (como se define por defecto en C)
// %p El puntero void * (dado como argumento se imprime en
//	formato hexadecimal)
// %d Imprime un número decimal (base 10)
// %i Imprime un entero en base 10
// %u Imprime un número decimal (base 10) sin signo
// %x Imprime un número hexadecimal (base 16) en minúsculas
// %X Imprime un número hexadecimal (base 16) en mayúsculas
// %% para imprimir el símbolo del porcentaje


int	flag_minus(char **format, long number)
{
	int min_width;
	int	len_number;
	int	fill_quantity;

	min_width = ft_atoi(*format);
	len_number = ft_strlen(ft_itoa(number));
	if (min_width > len_number)
		len_number = min_width;
	if (number < 0)
		write (1, "-", 1);
	fill_quantity = len_number - ft_putnbr(number);
	while (fill_quantity-- > 0)
		write(1, " ", 1);
	return (len_number);
}
int	flag_zero(char **format, long number)
{
	int min_width;
	int	len_number;
	int	fill_quantity;

	min_width = ft_atoi(*format);
	len_number = ft_strlen(ft_itoa(number));
	if (min_width > len_number)
		len_number = min_width;
	fill_quantity = min_width - ft_strlen(ft_itoa(number));
	if (number < 0)
		write (1, "-", 1);
	while (fill_quantity-- > 0)
		write(1, "0", 1);
	ft_putnbr(number);
	return (len_number);
}

int	only_field_min_width(char **format, long number)
{
	int min_width;
	int	len_number;
	int	fill_quantity;

	min_width = ft_atoi(*format);
	len_number = ft_strlen(ft_itoa(number));
	if (min_width > len_number)
		len_number = min_width;
	fill_quantity = min_width - ft_strlen(ft_itoa(number));
	while (fill_quantity-- > 0)
		write(1, " ", 1);
	if (number < 0)
		write (1, "-", 1);
	ft_putnbr(number);
	return (len_number);
}

int	manage_conv_number(char **format, long number)
{
	int	printed_chars;
	int	fill_quantity;

	if (**format == 'd' || **format == 'i')
		return (ft_putnbr(number));

	else if (**format == '-')
	{
		(*format)++;
		printed_chars = flag_minus(format, number);
	}
	else if (**format == '0')
	{
		(*format)++;
		printed_chars = flag_zero(format, number);
	}
	else if (ft_isdigit(**format))
		printed_chars = only_field_min_width(format, number);
	return (printed_chars);
}

int	get_conv_type(char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == 'd' || format[i] == 'i')
			return (1);
		else if (format[i] == 'c')
			return (2);
		else if (format[i] == 's')
			return (3);
		i++;
	}
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	va_start(args, format);
	int			number;
	int			count;
	char		*format_copy;

	count = 0;
	format_copy = (char *)format;
	while (*format_copy)
	{
		if (*format_copy == '%' && *(format_copy + 1))
		{
			format_copy++;
			if (get_conv_type(format_copy) == 1)
				count += manage_conv_number(&format_copy, va_arg(args, int));
 			else if (get_conv_type(format_copy) == 2)
				count += ft_putchar(va_arg(args, int));
			else if (get_conv_type(format_copy) == 3)
				count += ft_putstr(va_arg(args, char *));
			else if (*format_copy == '%')
				count += ft_putchar('%');
			while (*format_copy && *format_copy != 'd' && *format_copy != 'i' && *format_copy != 'c' && *format_copy != 's' && *format_copy != '%')
				format_copy++;
/*			if (format[i] == 'p')
			{

			} */
		}
		else
			count += ft_putchar(*format_copy);
		format_copy++;
	}
	return (count);
}
/* int	manage_c(char character)
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
} */
