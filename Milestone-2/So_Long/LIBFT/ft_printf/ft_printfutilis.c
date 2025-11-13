/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:08:56 by lmanzani          #+#    #+#             */
/*   Updated: 2025/05/21 23:55:43 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long n, char *base, unsigned int baselen)
{
	int	i;

	i = 0;
	if (n >= baselen)
		i += ft_putnbr_base(n / baselen, base, baselen);
	i += ft_putchar(base[n % baselen]);
	return (i);
}

int	ft_putnbr(int nb, int i)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	if (n > 9)
		i = ft_putnbr(n / 10, i);
	i += ft_putchar (n % 10 + '0');
	return (i);
}
