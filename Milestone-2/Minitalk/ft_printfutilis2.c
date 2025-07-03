/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutilis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:11:36 by lmanzani          #+#    #+#             */
/*   Updated: 2025/05/21 22:43:39 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchar(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_putptr(void *s)
{
	int				count;
	unsigned long	address;
	char			*hex_base;

	hex_base = "0123456789abcdef";
	count = 0;
	if (!s)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	address = (unsigned long)s;
	count += ft_putnbr_base(address, hex_base, 16);
	return (count);
}
