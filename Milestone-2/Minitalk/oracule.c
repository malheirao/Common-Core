#include "talk.h"

void handler(int signo, siginfo_t *info, void *more_info)
{
	(void)more_info;
	static char c;
	static int bit;
	static pid_t	consultant;

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
			Kill(consultant, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
	}
	kill(consultant, SIGUSR1);
}

int	main(void)
{
	/*ft_*/printf("ORACLE PID=%d\n", getpid());
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
