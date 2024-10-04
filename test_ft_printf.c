/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:30:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/04 11:52:22 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>

// Colores
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"


void test_printf(const char *format, ...) {
    char original_output[1024];
    char ft_output[1024];

    // Usar va_list para manejar argumentos variables
    va_list args;

    // Llamar a printf y capturar la salida
    va_start(args, format);
    int original_return = vsnprintf(original_output, sizeof(original_output), format, args);
    va_end(args);

    // Imprimir la salida original
    printf("Original printf output: %s", original_output);

    // Llamar a ft_printf y capturar la salida
    va_start(args, format);
    int ft_return = ft_printf(format, args);
    va_end(args);

    // La salida de ft_printf debe ser igual a original_output
    strcpy(ft_output, original_output); // Asegurarse de que se copia correctamente

    // Imprimir la salida de ft_printf
    ft_printf("ft_printf output: %s", ft_output);

    // Comparar resultados
    printf("Original printf returned: %d\n", original_return);
    printf("ft_printf returned: %d\n", ft_return);

    if (original_return == ft_return) {
        printf(GREEN "Return values match!\n" RESET);
    } else {
        printf("Return values do not match!\n");
    }

    // Comparar salidas
    if (strcmp(original_output, ft_output) == 0) {
        printf(GREEN "Output strings match!\n\n" RESET);
    } else {
        printf(RED "Output strings do not match!\n" RESET);
        printf("Original output: %s\n", original_output);
        printf("ft_printf output: %s\n\n", ft_output);
    }
}
int main() {
    printf(YELLOW"\n		------- TEST FT_PRINTF -------\n\n"RESET);

    // Pruebas de la función ft_printf
    printf("Hello, World!\n");
	ft_printf("Hello, World!\n\n");

    printf("Integer: %d\n", 42);
    ft_printf("Integer: %d\n\n", 42);

    printf("Negative Integer: %d\n", -42);
    ft_printf("Negative Integer: %d\n\n", -42);

    printf("String with newline\nand tab\tcharacter\n");
    ft_printf("String with newline\nand tab\tcharacter\n\n");

    printf("String with %d%% special character\n", 100);
    ft_printf("String with %d%% special character\n\n", 100);

    printf("Hexadecimal (lowercase): %x\n", 255);
    ft_printf("Hexadecimal (lowercase): %x\n\n", 255);

    printf("Hexadecimal (uppercase): %X\n", 255);
    ft_printf("Hexadecimal (uppercase): %X\n\n", 255);


    int var = 10;
    printf("Pointer: %p\n", (void*)&var);
    ft_printf("Pointer: %p\n\n", (void*)&var);

    printf("Character: %c\n", 'A');
    ft_printf("Character: %c\n\n", 'A');

    printf("Mixed: %d, %s, %c\n", 42, "example", 'Z');
    ft_printf("Mixed: %d, %s, %c\n\n", 42, "example", 'Z');

    printf("Width: [%s]\n", "test");
    ft_printf("Width: [%s]\n\n", "test");

    printf("\n");
    ft_printf("\n\n");

    printf("   \n");
    ft_printf("   \n\n");

	printf("Space before positive: [% d]\n", 42);
	ft_printf("Space before positive: [% d]\n\n", 42);

	printf("Space before negative: [% d]\n", -42);
	ft_printf("Space before negative: [% d]\n\n", -42);

	printf("Positive sign: [%+d]\n", 42);
	ft_printf("Positive sign: [%+d]\n\n", 42);

	printf("Negative sign: [%+d]\n", -42);
	ft_printf("Negative sign: [%+d]\n\n", -42);

	printf("Hexadecimal with # prefix (lowercase): [%#x]\n", 255);
	ft_printf("Hexadecimal with # prefix (lowercase): [%#x]\n\n", 255);

	printf("Hexadecimal with # prefix (uppercase): [%#X]\n", 255);
	ft_printf("Hexadecimal with # prefix (uppercase): [%#X]\n\n", 255);

	printf("Right-aligned: [%d]\n", 42);
	ft_printf("Right-aligned: [%d]\n\n", 42);

	printf("Left-aligned: [%d]\n", 42);
	ft_printf("Left-aligned: [%d]\n\n", 42);

	printf("Empty string: [%s]\n", "");
	ft_printf("Empty string: [%s]\n\n", "");

	printf("String with spaces: [%s]\n", "   ");
	ft_printf("String with spaces: [%s]\n\n", "   ");

	printf("Zero: [%d]\n", 0);
	ft_printf("Zero: [%d]\n\n", 0);

	char *s = NULL;

	printf("Null pointer: %p %s\n", NULL, s);
	ft_printf("Null pointer: %p %s\n", NULL, s);

	printf("Percentage: [%%]\n");
	ft_printf("Percentage: [%%]\n\n");

	printf("Negative with sign: [%+d]\n", -42);
	ft_printf("Negative with sign: [%+d]\n\n", -42);

	/*printf("Combined: [% #5d]\n", 42);
	ft_printf("Combined: [% #5d]\n", 42);*/

	printf("Combined: [%#x]\n", 255);
	ft_printf("Combined: [%#x]\n\n", 255);

	printf("Combined: [%+10d]\n", 42);
	ft_printf("Combined: [%+10d]\n\n", 42);



    printf("Complex: [%d] [%s] [%c]""		***\n", 42, "test", 'Z');
	ft_printf("Complex: [%d] [%s] [%c]""		***\n", 42, "test", 'Z');

    ft_printf("Integer: %d\n", 42);
	printf("Integer: %d\n\n", 42);

    ft_printf("Negative Integer: %d\n", -42);
	printf("Negative Integer: %d\n", -42);

    return 0;
}

