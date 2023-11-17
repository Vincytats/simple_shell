#include "shell.h"

/**
 * read_line - reads a line of input from user
 * @i_eof: a flag indicating whether the end of the file has been reached
 * Return: void
 */
char *read_line(int *i_eof)
{
char *input = NULL;
size_t bufsize = 0;
*i_eof = getline(&input, &bufsize, stdin);
return (input);
}
