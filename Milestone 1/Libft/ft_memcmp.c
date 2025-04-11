/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:28:04 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/11 14:36:31 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*source1;
	unsigned char	*source2;

	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*source1 != *source2)
			return (*source1 - *source2);
		source1++;
		source2++;
		n--;
	}
	return (0);
}
