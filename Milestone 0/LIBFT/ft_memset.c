/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:00:31 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/15 10:40:34 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*placeholder;

	placeholder = (unsigned char *)s;
	while (n > 0)
	{
		*placeholder = (unsigned char)c;
		placeholder++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{
	int a = argv[2][0];
	size_t n = 10;
	if (argc >= 3)
	{
		ft_memset(argv[1], a, n);
		printf("sua string é: %s", argv[1]);
	}		
}*/
