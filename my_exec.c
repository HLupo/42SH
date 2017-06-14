/*
** my_exec.c for my_exec in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Tue Apr 18 09:42:42 2017 SingeSumo
** Last update Fri Apr 21 19:59:25 2017 SingeSumo
*/

# include "my.h"

char	**my_setpath(char **path, char *cmd)
{
  int	i;
  char	*tmp1;
  char	*tmp2;

  i = -1;
  if ((my_getenv("PATH", &i)) != NULL)
    path = my_wordtab(tmp1 = my_sdup((env[i] + 5)), ":");
  else
    path = my_wordtab(tmp1 = my_sdup(basicpath), ":");
  i = -1;
  while (path != NULL && path[++i] != NULL)
    {
      (tmp2 = (path[i] = my_scat(path[i], "/")));
      path[i] = my_scat(path[i], cmd);
      free(tmp2);
    }
  free(tmp1);
  return (path);
}

char	**my_lscolors(char **cmd)
{
  int	i;
  char	**new;

  i = -1;
  return (cmd);
  if ((my_scmp((cmd[0] + my_strlen(cmd[0], 0) - 2), "ls", 3)) != 0)
    return (cmd);
  while (cmd[++i] != NULL);
  if ((new = my_tabrealloc(cmd, 1)) == NULL)
    return (NULL);
  i = 0;
  new[1] = "--color";
  while (cmd[++i] != NULL)
    new[i + 1] = cmd[i];
  free(cmd);
  return (new);
}

int	my_access(char *cmd)
{
  int	i;

  i = ((access(cmd, R_OK)) == 0) ? 1 : 0;
  i = ((i != 0) && (access(cmd, X_OK)) == 0) ? 2 : i;
  return (i);
}

int	my_exec(char *cmd, char **arg)
{
  DIR	*mescouilles;
  int	a;
  int	pid;

  a = 0;
  errno = 0;
  mescouilles = opendir(cmd);
  closedir(mescouilles);
  if (errno == 0)
    return (r = my_printf(2, "%s: Permission denied.\n", cmd) + 1);
  if ((pid = fork()) != 0)
    r = my_execerror(pid);
  if ((pid == 0) && (a = execve(cmd, arg, env)) == -1)
    my_printf(2, "%s: Exec format error. Binary file not executable.\n", cmd);
  if (a == -1)
    exit(1);
  return (a);
}

int	my_command(char **cmd, char ***tmp)
{
  int	i;
  int	j;
  char	**path;

  path = NULL;
  i = my_access(cmd[0]);
  if (i == 1)
    return (r = (my_printf(2, "%s: Permission denied.\n", cmd[0])) + 1);
  cmd = my_lscolors(cmd);
  (*tmp) = cmd;
  if (i == 2)
    return (my_exec(cmd[0], cmd));
  if ((path = my_setpath(path, cmd[0])) == NULL)
    return (84);
  i = (j = -1);
  while (path != NULL && path[++i] != NULL && (my_access(path[i])) != 2);
  while (path[0][++j] != '\0')
    if (path[i] == NULL || (path[0][j] == '/' && path[0][j + 1] == '/'))
      {
	my_freetab(path);
	return (r = (my_printf(2, "%s: Command not found.\n", cmd[0])) + 1);
      }
  my_exec(path[i], cmd);
  my_freetab(path);
  return (0);
}
