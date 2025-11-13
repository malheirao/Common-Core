/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:52:14 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/16 13:20:19 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dest_cpy;

	if (n == 0 || src == dest)
		return (dest);
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	dest = (void *)dest_cpy;
	return (dest);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{	
	size_t n = 5;
	if (argc >= 3)
	{
		ft_memcpy(argv[1], argv[2], n);
		printf("sua string copiada é: %s", argv[1]);
	}
}*/
