/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:00:22 by lmanzani          #+#    #+#             */
/*   Updated: 2025/11/05 19:00:55 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../LIBFT/libft.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	player_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}
