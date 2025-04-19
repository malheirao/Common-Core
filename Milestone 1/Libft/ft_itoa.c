/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:03:02 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/19 15:53:46 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_completestr(int n, size_t len, size_t neg)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[len + neg] = '\0';
	len--;
	while (n >= 10)
	{
		str[len + neg] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[len + neg] = n + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	len = ft_numlen(n);
	return (ft_completestr(n, len, neg));
}
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int num = atoi(argv[1]); // converte a string para inteiro
        char *result = ft_itoa(num);
        printf("seu itoa ficou: %s\n", result);
        free(result); // sempre libera a memória alocada
    }
    else
    {
        printf("Uso: ./a.out <numero>\n");
    }
    return 0;
}*/
