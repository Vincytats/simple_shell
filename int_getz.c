#include "shell.h"

/**
 * get_sigint - handles the SIGINT signal
 * @sig: signal number
 * Return: void
 */
void get_sigint(int sig)
{
(void)sig;
write(STDOUT_FILENO, "\n^-^ ", 5);
}
