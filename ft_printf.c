/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:06:34 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/08 14:35:08 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	ft_handle(const char c, va_list arguments, int count)
{

	if (c == 'c')
		count = ft_print_char(va_arg(arguments, int), count);
	else if (c == 's')
		count = ft_print_str(va_arg(arguments, char *), count);
	else if (c == 'i' || c == 'd')
		count = ft_print_digits(va_arg(arguments, int), count);
	else if (c == 'p')
		count = ft_print_pointers(va_arg(arguments, void *), count);

	return(count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arguments;
	int			characters;
	int 		index;

	characters = 0;
	index = 0;
	va_start(arguments, format);
	
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			characters = ft_handle((char)format[index], arguments, characters);
		}
		else
			characters = ft_print_char(format[index], characters);
		index ++;
	}
	va_end(arguments);
	return (characters);
}
