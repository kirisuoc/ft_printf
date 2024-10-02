/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:06:58 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/10 11:13:59 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// bzero es una forma simplificada de memset, para cuando se va a escribir 0
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
