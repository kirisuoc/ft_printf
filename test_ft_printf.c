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
    test_printf("Hello, World!\n");
    test_printf("Integer: %d\n", 42);
    test_printf("Negative Integer: %d\n", -42);
    test_printf("String with newline\nand tab\tcharacter\n");
    test_printf("String with %d%% special character\n", 100);
    test_printf("Hexadecimal (lowercase): %x\n", 255);
    test_printf("Hexadecimal (uppercase): %X\n", 255);
    
    int var = 10;
    test_printf("Pointer: %p\n", (void*)&var);
    test_printf("Character: %c\n", 'A');
    test_printf("Mixed: %d, %s, %c\n", 42, "example", 'Z');
    test_printf("Width: [%10s]\n", "test");
    test_printf("\n");
    test_printf("   \n");
	test_printf("Space before positive: [% d]\n", 42);
	test_printf("Space before negative: [% d]\n", -42);
	test_printf("Positive sign: [%+d]\n", 42);
	test_printf("Negative sign: [%+d]\n", -42);
	test_printf("Octal with # prefix: [%#o]\n", 42);
	test_printf("Hexadecimal with # prefix (lowercase): [%#x]\n", 255);
	test_printf("Hexadecimal with # prefix (uppercase): [%#X]\n", 255);
	test_printf("Right-aligned: [%5d]\n", 42);
	test_printf("Left-aligned: [%-5d]\n", 42);
	test_printf("Empty string: [%s]\n", "");
	test_printf("String with spaces: [%s]\n", "   ");
	test_printf("Zero: [%d]\n", 0);
	test_printf("Null pointer: %p\n", NULL);
	test_printf("Percentage: [%%]\n");
	test_printf("Negative with sign: [%+d]\n", -42);
	test_printf("Negative octal: [%o]\n", -42); // Puede depender de tu implementación
	test_printf("Precision truncation: [%.5s]\n", "Hello, World!");
	test_printf("Combined: [% #5d]\n", 42);
	test_printf("Combined: [%#10x]\n", 255);
	test_printf("Combined: [%+10d]\n", 42);


    test_printf("Complex: [%5d] [%10s] [%c]""		***\n", 42, "test", 'Z');

    ft_printf("Integer: %d\n", 42);
	printf("Integer: %d\n", 42);

    ft_printf("Negative Integer: %d\n", -42);
	printf("Negative Integer: %d\n", -42);

    return 0;
}

