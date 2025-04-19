/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:03:57 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/19 17:50:48 by lmanzani         ###   ########.fr       */
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
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void print_result(char **res)
{
    int i = 0;
    while (res && res[i])
    {
        printf("Palavra %d: \"%s\"\n", i, res[i]);
        i++;
    }

    // Libera a memória alocada
    i = 0;
    while (res && res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}

int main(void)
{
    char *ex1 = "ola tudo bem amigo";
    char *ex2 = "   isso  é   uma   string   cheia  de espaços ";
    char *ex3 = ":::::dividir::::com::::dois-pontos:::::";
    char *ex4 = "";  // string vazia
    char *ex5 = "semseparador"; // sem separador
    char sep1 = ' ';
    char sep2 = ':';

    printf("Exemplo 1:\n");
    print_result(ft_split(ex1, sep1));

    printf("\nExemplo 2:\n");
    print_result(ft_split(ex2, sep1));

    printf("\nExemplo 3:\n");
    print_result(ft_split(ex3, sep2));

    printf("\nExemplo 4:\n");
    print_result(ft_split(ex4, sep1));

    printf("\nExemplo 5:\n");
    print_result(ft_split(ex5, sep2));

    return 0;
}*/
