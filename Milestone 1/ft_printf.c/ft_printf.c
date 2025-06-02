/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:16:48 by lmanzani          #+#    #+#             */
/*   Updated: 2025/06/02 08:58:54 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printformat(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int), 0);
	else if (specifier == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned int),
				"0123456789", 10);
	else if (specifier == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int),
				"0123456789abcdef", 16);
	else if (specifier == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int),
				"0123456789ABCDEF", 16);
	return (count);
}

int	ft_ispercentage(const char **str, va_list ap)
{
	int	count;

	count = 0;
	if (**str == '%')
	{
		(*str)++;
		if (ft_strchar("cspdiuxX", **str))
		{
			count += ft_printformat(**str, ap);
			(*str)++;
		}
		else
			count = count + ft_putchar(*((*str)++));
	}
	else
	{
		count = count + ft_putchar(**str);
		(*str)++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
		count += ft_ispercentage(&format, ap);
	va_end(ap);
	return (count);
}
