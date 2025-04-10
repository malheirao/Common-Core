/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:41:46 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:01 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	char tmpc;
	char *tmps;

	i = 0;
	tmps = (char*)s;
	tmpc = c;
	while (tmps[i] != tmpc)
	{
		if (tmps[i] == '\0')
	{
		return (NULL);
        }
	i++;
	}
    return ((char*)tmps + i);
}

