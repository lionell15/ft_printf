/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:21:37 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/11 13:21:58 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(unsigned int n, int count)
{
	if (n > 9)
		count = ft_print_unsigned(n / 10, count);
	count = ft_print_char (n % 10 + '0', count);
	return (count);
}
