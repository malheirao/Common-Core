/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:01:09 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/17 16:54:25 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("antes do tolower: %c\n",(*argv[1]));
		printf("depois do tolower: %c",ft_tolower(*argv[1]));
	}
}*/
