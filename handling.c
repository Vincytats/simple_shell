#include "shell.h"

/**
 * _memcpy - size bytes
 * @newptr: pointer to the destination memory area
 * @ptr: pointer to the source memory area
 * @size: number of bytes to copy
 * Return: a pointer to the destination memory area
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
char *char_ptr = (char *)ptr;
char *char_newptr = (char *)newptr;
unsigned int i;
for (i = 0; i < size; i++)
char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - reallocates memory block
 * @ptr: pointer to the previously allocated memory
 * @old_size: size of old memory block
 * @new_size: size of new memory block
 * Return: pointer to the reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *newptr;
if (ptr == NULL)
return (malloc(new_size));
if (new_size == 0)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
return (ptr);
newptr = malloc(new_size);
if (newptr == NULL)
return (NULL);
if (new_size < old_size)
_memcpy(newptr, ptr, new_size);
else
_memcpy(newptr, ptr, old_size);
free(ptr);
return (newptr);
}

/**
 * _reallocdp - reallocates a memory block for a pointer to pointer
 * @ptr:pointer to the previously allocated memory
 * @old_size: size of the old memory block
 * @new_size: size of new memory block
 * Return: a pointer to reallocated memory
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
char **newptr;
unsigned int i;
if (ptr == NULL)
return (malloc(sizeof(char *) * new_size));
if (new_size == old_size)
return (ptr);
newptr = malloc(sizeof(char *) * new_size);
if (newptr == NULL)
return (NULL);
for (i = 0; i < old_size; i++)
newptr[i] = ptr[i];
free(ptr);
return (newptr);
}
