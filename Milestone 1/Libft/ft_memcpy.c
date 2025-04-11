/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:52:14 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/10 14:53:12 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*altdst;
	unsigned char	*altsrc;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	while (n > 0)
	{
		*tmpdst = *tmpsrc;
		tmpdst++;
		tmpsrc++;
		n--;
	}
	return (dst);
}
