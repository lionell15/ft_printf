/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:20:17 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/11 13:21:20 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(const char *str, int count)
{
	int	index;

	index = 0;
	if (!str)
		str = "(null)";
	while (str[index])
	{
		count = ft_print_char(str[index], count);
		index++;
	}
	return (count);
}
