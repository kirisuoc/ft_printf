/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:59 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/27 17:06:37 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(char const *, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int n);

#endif
