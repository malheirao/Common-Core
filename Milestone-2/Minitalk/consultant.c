#include "talk.h"

volatile sig_atomic_t	g_oracle = BUSY;

void	end_handler(int signo)
{
	write(STDOUT_FILENO, "Fine!\n", 7);
	exit(EXIT_SUCCESS);
}

void	ack_handler(int signo)
{
	g_oracle = READY;
}

void	send_char(char c, pid_t oracle)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			Kill(oracle, SIGUSR1);
		else
			Kill(oracle, SIGUSR2);
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
	Signal(SIGUSR1, ack_handler, false);
	Signal(SIGUSR2, end_handler, false);
	while (*message)
		send_char(*message++, oracle);
	send_char('\0', oracle);
	return (EXIT_SUCCESS);
}
