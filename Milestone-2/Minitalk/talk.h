/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <lmanzani@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:41:53 by lmanzani          #+#    #+#             */
/*   Updated: 2025/07/03 10:37:11 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TALK_H
# define TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

enum
{
	READY,
	BUSY,
};

void	void_signal(int signo, void *handler, bool use_siginfo);
void	void_kill(pid_t pid, int signo);

#endif
