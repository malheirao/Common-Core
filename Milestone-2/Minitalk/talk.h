

#ifndef TALK_H
#define TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

enum{
	READY,
	BUSY,
};

void	Signal(int, void *, bool);
void	Kill(pid_t, int);

#endif
