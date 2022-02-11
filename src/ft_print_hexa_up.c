/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:18:09 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/11 13:18:47 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa_up(unsigned int hx, int count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (hx > 15)
		count = ft_print_hexa_up(hx / 16, count);
	count = ft_print_char(base[hx % 16], count);
	return (count);
}
