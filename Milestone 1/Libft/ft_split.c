/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:03:57 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/17 15:07:59 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **dest, int count);
static int	ft_count_words(const char *str, char sep);
static char	**ft_completew(char **dest, const char *s, char c, int *i);

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	if (!s)
		return (NULL);
	dest = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	dest = ft_completew(dest, s, c, &i);
	if (!dest)
		return (NULL);
	dest[i] = NULL;
	return (dest);
}

static int	ft_count_words(const char *str, char sep)
{
	int	i;
	int	words;

	if (!str || !str[0])
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0' && str[i] != sep)
			words++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (words);
}

static char	**ft_completew(char **dest, const char *s, char c, int *i)
{
	size_t	len;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			dest[*i] = ft_substr(s, 0, len);
			if (!dest[*i])
			{
				ft_free(dest, *i);
				return (NULL);
			}
			s += len;
			(*i)++;
		}
	}
	return (dest);
}

static void	ft_free(char **dest, int count)
{
	while (count > 0)
		free(dest[--count]);
	free(dest);
}
