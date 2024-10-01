/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:57:10 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/01 17:50:05 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"

/*	__ Bonus 1 __
	- : Justificación a la izquierda. El valor se imprime
		alineado a la izquierda.
	0 : Relleno con ceros en lugar de espacios.
	. : Indica la precisión para números decimales o la cantidad de
		dígitos que se deben
		imprimir para números enteros.
*/

// %c Imprime un solo caracter 								OK
// %s Imprime una string (como se define por defecto en C)	OK
// %p El puntero void * (dado como argumento se imprime en	OK
//	formato hexadecimal)
// %d Imprime un número decimal (base 10)					OK
// %i Imprime un entero en base 10							OK
// %u Imprime un número decimal (base 10) sin signo
// %x Imprime un número hexadecimal (base 16) en minúsculas
// %X Imprime un número hexadecimal (base 16) en mayúsculas
// %% para imprimir el símbolo del porcentaje /*

/*int	manage_conv_number(char **format, long number)
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
} */

static int	process_format(t_format *info, va_list *args)
{
	int	printed_chars;

	printed_chars = 0;
	if (info->specifier == 'c')
		printed_chars += ft_putchar(va_arg(*args, int));
	else if (info->specifier == 'd' || info->specifier == 'i')
		printed_chars += manage_d(info, args);
	else if (info->specifier == 'p')
		printed_chars += manage_p(info, args);
	else if (info->specifier == 's')
		printed_chars += ft_putstr(va_arg(*args, char *));
	else if (info->specifier == 'u')
		printed_chars += ft_putnbr_unsigned(va_arg(*args, unsigned int));
/*	else if (info->specifier == 'x' || info->specifier == 'X') */
	else if (info->specifier == '%')
		printed_chars += ft_putchar('%');
	return (printed_chars);
}

int	ft_printf(char const *format, ...)
{
	int			count;
	char		*format_copy;
	t_format	info;
	va_list		args;

	va_start(args, format);
	count = 0;
	format_copy = (char *)format;
	while (*format_copy)
	{
		if (*format_copy == '%' && *(format_copy + 1))
		{
			format_copy++;
			ft_bzero(&info, sizeof(info));
			parse_format(&format_copy, &info);
			count += process_format(&info, &args);
		}
		else
			count += ft_putchar(*format_copy);
		format_copy++;
	}
	va_end(args);
	return (count);
}
