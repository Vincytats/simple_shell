#include "shell.h"

/**
 * bring_line - brings a line to buffer
 * @lineptr: pointer to the line buffer
 * @buffer: buffer to store the line
 * @n: number of characters in line bufer
 * @j: number of specifying some information about the line
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
if (*lineptr == NULL)
{
if  (j > BUFSIZE)
*n = j;
else
*n = BUFSIZE;
*lineptr = buffer;
}
else if (*n < j)
{
if (j > BUFSIZE)
*n = j;
else
*n = BUFSIZE;
*lineptr = buffer;
}
else
{
_strcpy(*lineptr, buffer);
free(buffer);
}
}
/**
 * get_line -reads a line from a stream
 * @lineptr: pointer to the line buffer
 * @n: number of characters to read
 * @stream: stream from which to read the line
 * Return: void
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
int i;
static ssize_t input;
ssize_t retval;
char *buffer;
char t = 'z';
if (input == 0)
fflush(stream);
else
return (-1);
input = 0;
buffer = malloc(sizeof(char) * BUFSIZE);
if (buffer == 0)
return (-1);
while (t != '\n')
{
i = read(STDIN_FILENO, &t, 1);
if (i == -1 || (i == 0 && input == 0))
{
free(buffer);
return (-1);
}
if (i == 0 && input != 0)
{
input++;
break;
}
if (input >= BUFSIZE)
buffer = _realloc(buffer, input, input + 1);
buffer[input] = t;
input++;
}
buffer[input] = '\0';
bring_line(lineptr, n, buffer, input);
retval = input;
if (i != 0)
input = 0;
return (retval);
}
