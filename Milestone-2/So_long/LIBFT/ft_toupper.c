/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:58:43 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/17 16:55:05 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
        if (argc == 2)
        {
                printf("antes do toupper: %c\n",(*argv[1]));
                printf("depois do toupper: %c",ft_toupper(*argv[1]));
        }
}*/
