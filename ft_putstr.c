/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:47:39 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/27 16:54:54 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

int	ft_putstr(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (!*s)
		return (0);
	write (1, s, len);
	return (len);
}
