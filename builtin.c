#include "shell.h"

/**
 * get_builtin -gets the builtin function
 * @cmd: the command
 * Return: a function pointer to the associated built in function
 */
int (*get_builtin(char *cmd))(data_shell *)
{
builtin_t builtin[] = {
{ "env", _env },
{ "exit", exit_shell },
{ "setenv", _setenv },
{ "unsetenv", _unsetenv },
{ "cd", cd_shell },
{ "help", get_help },
{ NULL, NULL }
};
int i;
for (i = 0; builtin[i].name; i++)
{
if (_strcmp(builtin[i].name, cmd) == 0)
break;
}
return (builtin[i].f);
}
