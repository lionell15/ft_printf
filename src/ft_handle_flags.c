/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:31:55 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/08 14:32:31 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags	ft_minus_flag(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_digit_flag(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

int	ft_dot_flag(const char *str, int start, t_flags *flags, va_list args)
{
	int	i;

	i = start;
	i = i + 1;
	if (str[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i = i + 1;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags->dot = (flags->dot * 10) + (str[i] - 48);
			i = i + 1;
		}
	}
	return (i);
}
