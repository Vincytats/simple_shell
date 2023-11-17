#include "shell.h"

/**
 * cmp_env_name - compares an environment name
 * @nenv: the name of the environment variable to compare
 * @name: the name to compare with
 * Return: 0 if the names are equal, positive value if nenv is greater
 */
int cmp_env_name(const char *nenv, const char *name)
{
int i;
for (i = 0; nenv[i] != '='; i++)
{
if (nenv[i] != name[i])
{
return (0);
}
}
return (i + 1);
}

/**
 * _getenv -gets the value of an environment variable
 * @name: name of environment variable to retrieve
 * @_environ:the environment variable array
 * Return: a pointer to the value of specified environment variable
 */
char *_getenv(const char *name, char **_environ)
{
char *ptr_env;
int i, mov;
/* Init ptr_env val */
ptr_env = NULL;
mov = 0;
/*retrieve value of the specified environment */
/*Return a pointer to NULL  */
for (i = 0; _environ[i]; i++)
{
/*Return a pointer to null */
mov = cmp_env_name(_environ[i], name);
if (mov)
{
ptr_env = _environ[i];
break;
}
}
return (ptr_env + mov);
}

/**
 * _env -prints current environment variable
 * @datash: data structure containing information about shell
 * Return: void
 */
int _env(data_shell *datash)
{
int i, j;
for (i = 0; datash->_environ[i]; i++)
{
for (j = 0; datash->_environ[i][j]; j++)
;
write(STDOUT_FILENO, datash->_environ[i], j);
write(STDOUT_FILENO, "\n", 1);
}
datash->status = 0;
return (1);
}
