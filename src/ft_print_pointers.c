/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:18:56 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/11 13:20:10 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa_lower(unsigned long long hexa, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (hexa > 15)
		count = ft_print_hexa_lower(hexa / 16, count);
	count = ft_print_char(base[hexa % 16], count);
	return (count);
}

int	ft_print_pointers(void *ptr, int count)
{
	count = ft_print_str("0x", count);
	count = ft_print_hexa_lower((unsigned long long)ptr, count);
	return (count);
}
