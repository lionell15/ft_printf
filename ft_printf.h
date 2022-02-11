/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:07:19 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/08 14:39:17 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(const char c, int count);
int		ft_print_str(const char *str, int count);
int		ft_print_digits(int n, int count);
int		ft_print_pointers(void *ptr, int count);
int		ft_print_unsigned(unsigned int n, int count);
int		ft_print_hexa_low(unsigned int hx, int count);
int		ft_print_hexa_up(unsigned int hx, int count);
#endif
