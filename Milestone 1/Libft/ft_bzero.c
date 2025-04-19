/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:24:11 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/19 15:24:13 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("sua string eh :%s\ndepois fica:%s", argv[1], ft_bzero(, 3));
	}
}*/
