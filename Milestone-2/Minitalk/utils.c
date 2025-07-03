/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:56:47 by lmanzani          #+#    #+#             */
/*   Updated: 2025/07/03 11:47:05 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*placeholder;

	placeholder = (unsigned char *)s;
	while (n > 0)
	{
		*placeholder = (unsigned char)c;
		placeholder++;
		n--;
	}
	return (s);
}

void	void_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		perror("void_kill failed");
		exit(EXIT_FAILURE);
	}
}

void	void_signal(int signo, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signo, &sa, NULL) < 0)
	{
		perror("Sigaction Failed");
		exit(EXIT_FAILURE);
	}
}
