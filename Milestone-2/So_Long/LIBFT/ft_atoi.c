/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:55 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/19 15:47:15 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

size_t	skip_whitespaces(const char *str, size_t z)
{
	while (ft_isspace(str[z]))
		z++;
	return (z);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	z;
	size_t	sign;

	i = 0;
	z = 0;
	sign = 1;
	z = skip_whitespaces (str, z);
	if (str[z] == '-')
	{
		sign = -1;
		z++;
	}
	else if (str[z] == '+')
	{
		sign = 1;
		z++;
	}
	while (str[z] && str[z] >= '0' && str[z] <= '9')
	{
		i = i * 10 + str[z] - '0';
		z++;
	}
	return (i * sign);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("seu atoi e: %d", ft_atoi(argv[1]));
	}
	return (0);
}*/
