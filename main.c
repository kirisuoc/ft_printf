/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:18:03 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/07 13:27:34 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int b =    printf("%d\n", -2147483648);
	int d = printf("%d\n", INT_MIN);

	printf("%d\n", b);
	printf("%d\n", d);
	return (0);
}
