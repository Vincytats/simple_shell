#include "shell.h"

/**
 * get_sigint - function
 * @sig: Return
 */
void get_sigint(int sig)
{
(void)sig;
write(STDOUT_FILENO, "\n^-^ ", 5);
}
