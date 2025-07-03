/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consultant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:47:52 by lmanzani          #+#    #+#             */
/*   Updated: 2025/07/03 11:35:10 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"
#include "ft_printf.h"

volatile sig_atomic_t	g_oracle = BUSY;

void	end_handler(int signo)
{
	signo = 0;
	write(STDOUT_FILENO, "Fine!\n", 7);
	exit(EXIT_SUCCESS);
}

void	ack_handler(int signo)
{
	signo = 0;
	g_oracle = READY;
}

void	send_char(char c, pid_t oracle)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			void_kill(oracle, SIGUSR1);
		else
			void_kill(oracle, SIGUSR2);
		++bit;
		while (BUSY == g_oracle)
			usleep(42);
		g_oracle = BUSY;
	}
}

int	main(int ac, char **av)
{
	pid_t	oracle;
	char	*message;

	if (3 != ac)
	{
		fputs("Use = ./consultant <PID > \"request\"\n", stderr);
		exit (EXIT_FAILURE);
	}
	oracle = atoi(av[1]);
	message = av[2];
	void_signal(SIGUSR1, ack_handler, false);
	void_signal(SIGUSR2, end_handler, false);
	while (*message)
		send_char(*message++, oracle);
	send_char('\0', oracle);
	return (EXIT_SUCCESS);
}
