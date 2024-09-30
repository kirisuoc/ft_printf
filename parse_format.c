/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:34:17 by erikcousill       #+#    #+#             */
/*   Updated: 2024/09/30 08:38:16 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libftprintf.h"

static void	parse_format_flag_width(char **format, t_format *info)
{
	if (**format == '-')
	{
		info->flag_minus = 1;
		(*format)++;
	}
	else if (**format == '0')
	{
		info->flag_zero = 1;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		if (**format == '0')
			(*format)++;
		info->min_width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}
static void	parse_format_precision_identif(char **format, t_format *info)
{
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			info->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
		{
			info->precision = 0;
		}
	}
	if (**format == 'd' || **format == 'i' || **format == 'c'
		|| **format == 's' || **format == 'p' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == '%')
			info->specifier = **format;
}

void	parse_format(char **format, t_format *info)
{
	parse_format_flag_width(format, info);
	parse_format_precision_identif(format, info);
}
