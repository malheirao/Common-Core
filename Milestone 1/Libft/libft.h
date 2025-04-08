/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:03:14 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/08 13:15:06 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int	ft_isalpha(int i);
int	ft_isdigit(int i);
int	ft_isalnum(int i);
int	ft_isascii(int i);
int	ft_isprint(int i);
size_t	ft_strlen(const char *s);

#endif
