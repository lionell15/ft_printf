/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:06:34 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/07 14:06:42 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_input(const char *format, va_list arguments)
{
	int	index;
	int count;
	t_flags flags;

	index = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[index] != NULL)
	{
		flags = ft_initialize();
		if (format[index] != '%')
			count += ft_putchar(format[index]);
		else if (format[index] == '%' && format[index + 1])
		{
			index = ft_parse(format, ++i, &flags, arguments);
			if ft_isconversion(format[index])
				count += ft_handle((char)flags.type, flags, arguments);
			else if (format[index])
				count += ft_putchar(format[index]);
		}
		index++;
	}
	return (count);

}

int	ft_printf(const char *format, ...)
{
	va_list		arguments;
	const char	*str_format;
	int			characters;

	characters = 0;
	str_format = ft_strdup(format);
	if (!(str_format))
		return (0);
	va_start(arguments, format);
	printf("format:%s", str_format);
	characters += ft_check_input(str_format, arguments);
	va_end(arguments);
	free((char *)str_format);
	return (characters);
}
