/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:04:12 by lmanzani          #+#    #+#             */
/*   Updated: 2025/06/02 09:09:54 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printformat(char specifier, va_list ap);
int		ft_ispercentage(const char **str, va_list ap);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base(unsigned long n, char *base, unsigned int baselen);
int		ft_putnbr(int nb, int i);
char	*ft_strchar(const char *s, int c);
int		ft_putptr(void *s);
int		ft_printf(const char *format, ...);
#endif
