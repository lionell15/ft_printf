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
# include "utils/utils.h"
# include <stdio.h>

typedef struct s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}t_flags;

int		ft_printf(const char *format, ...);
int		ft_handle(int c, t_flags flags, va_list arguments);
int		ft_handle_width(int width, int minus, int zero);
int		ft_handle_char(char c, t_flags flags);
int	ft_handle_percent(t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);
int		ft_isconversion(int c);
int		ft_isflag(int c);
int		ft_dot_flag(const char *str, int start, t_flags *flags, va_list args);
t_flags	ft_digit_flag(char c, t_flags flags);
t_flags	ft_minus_flag(t_flags flags);

#endif
