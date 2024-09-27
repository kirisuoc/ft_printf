/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:57:10 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/27 17:47:22 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>

// %c Imprime un solo caracter
// %s Imprime una string (como se define por defecto en C)
// %p El puntero void * (dado como argumento se imprime en formato hexadecimal)
// %d Imprime un número decimal (base 10)
// %i Imprime un entero en base 10
// %u Imprime un número decimal (base 10) sin signo
// %x Imprime un número hexadecimal (base 16) en minúsculas
// %X Imprime un número hexadecimal (base 16) en mayúsculas
// %% para imprimir el símbolo del porcentaje

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

int	ft_printf(char const *format, ...)
{
	va_list		args;		// Define una variable que almacenará los argumentos pasados
	va_start(args, format);	// Inicializa el objeto 'va_list' para acceder a los argumentos
							// va_arg recupera los argumentos uno por uno, especificando el tipo
							// va_end limpia la variable va_list
	int			i;
	int			num;
	char		character;
	char		*string;
	int			count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				character = va_arg(args, int);
				ft_putchar_fd(character, 1);
				count++;
			}
			if (format[i] == 's')
			{
				string = va_arg(args, char *);
				count += ft_putstr(string);
			}
			if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(args, int);
				count += ft_putnbr(num);
			}
			if (format[i] == 'p')
			{

			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
