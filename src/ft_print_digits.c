/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:15:51 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/11 13:16:45 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_digits(int n, int count)
{
	long int	number;

	number = n;
	if (number < 0)
	{
		count = ft_print_char('-', count);
		number *= -1;
	}
	if (number > 9)
		count = ft_print_digits(number / 10, count);
	count = ft_print_char(number % 10 + '0', count);
	return (count);
}
