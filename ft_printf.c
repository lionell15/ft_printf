/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:06:34 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/07 20:40:56 by lionell15        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

static int	ft_parse(const char * format, int index, t_flags *flags, va_list arguments)
{
	while (format[index] != '\0')
	{
		if (! ft_isconversion(format[index]) && !ft_isflag(format[index]) && !ft_isdigit(format[index]))
			break;
		if (format[index] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[index] == '*')
			*flags = ft_width_flag(arguments, *flags);
		if (format[index] == '.')
			index = ft_dot_flag(format, index, flags, arguments);
		if (format[index] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(format[index]))
			*flags = ft_isdigit_flag(format[index], *flags);
		if (ft_isconversion(format[index]))
		{
			flags->type = format[index];
			break;
		}
		index++;
	}
	return (index);
}

static int	ft_check_input(const char *format, va_list arguments)
{
	int	index;
	int count;
	t_flags flags;

	index = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[index] != '\0')
	{
		flags = ft_init_flags();
		if (format[index] != '%')
			count += ft_putchar(format[index]);
		else if (format[index] == '%' && format[index + 1])
		{
			index = ft_parse(format, ++index, &flags, arguments);
			if (ft_isconversion(format[index]))
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
	characters += ft_check_input(str_format, arguments);
	va_end(arguments);
	free((char *)str_format);
	return (characters);
}
