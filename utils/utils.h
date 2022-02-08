/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:07:47 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/07 14:07:51 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_putchar(char c);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_putsp(char *str, int precision);
int		ft_tolower(int c);
char	*ft_str_tolower(char *str);
char	*ft_u_itoa(unsigned int n);
char	*ft_utl_base(unsigned long long number, int base);
#endif
