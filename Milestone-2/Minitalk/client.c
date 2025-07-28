/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by lmanzani          #+#    #+#             */
/*   Updated: 2025/07/04 18:36:09 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "talk.h"

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t		pid;
	char		*msg;

	if (ac != 3)
	{
		write(2, "Usage: ./client <PID> \"message\"\n", 32);
		return (1);
	}
	pid = (pid_t)ft_atoi(av[1]);
	msg = av[2];
	while (*msg)
		send_char(*msg++, pid);
	send_char('\0', pid);
	return (0);
}
