/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:25:50 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/08 14:31:38 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_isconversion(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

t_flags	ft_width_flag(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int	ft_handle_width(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}

int	ft_handle(int c, t_flags flags, va_list arguments)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_handle_char(va_arg(arguments, int), flags);
	else if (c == '%')
		count += ft_handle_percent(flags);
	/*
	else if (c == 'p')
		count = ft_handle_pointer(va_arg(arguments, unsigned long long), flags);
	else if (c == 's')
		count = ft_handle_string(va_arg(arguments, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_handle_int(va_arg(arguments, int), flags);
	else if (c == 'x')
		count += ft_handle_hex(va_arg(arguments, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_handle_hex(va_arg(arguments, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_handle_uint((unsigned int)va_arg(arguments, unsigned int),
				flags);
	*/
	return (count);
}
