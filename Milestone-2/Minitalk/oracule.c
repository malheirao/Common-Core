/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oracule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:48:29 by lmanzani          #+#    #+#             */
/*   Updated: 2025/07/03 11:40:39 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"
#include "ft_printf.h"

void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		c;
	static int		bit;
	static pid_t	consultant;

	(void)more_info;
	if (info->si_pid)
		consultant = info->si_pid;
	if (SIGUSR1 == signo)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0b10000000 >> bit);
	++bit;
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			write(STDOUT_FILENO, "\n", 1);
			void_kill(consultant, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
	}
	kill(consultant, SIGUSR1);
}

int	main(void)
{
	ft_printf("ORACLE PID=%d\n", getpid());
	void_signal(SIGUSR1, handler, true);
	void_signal(SIGUSR2, handler, true);
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
