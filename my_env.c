/*
** my_env.c for my_env in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Fri Apr 14 14:16:58 2017 SingeSumo
** Last update Fri Apr 21 11:44:05 2017 SingeSumo
*/

# include "my.h"

char	*my_getenv(char *path, int *l)
{
  int	i;

  i = -1;
  while (env != NULL && env[++i] != NULL)
    if ((my_scmp(path, env[i], my_strlen(path, '\0'))) == 0)
      return (env[(*l) = i]);
  (*l) = i;
  return (NULL);
}

int	my_checksetenv(char **cmd, int i)
{
  int	u;
  char	c;
  int	e;

  u = 122;
  c = cmd[1][0];
  e = my_isalpha(cmd[1]);
  if (e == 0 && i <= 3 && (c == 95 || (c > 64 && c < 91) || (c > 96 && c < u)))
    return (0);
  my_printf(2, "setenv: ");
  if (i > 3)
    my_printf(1, "Too many arguments.\n");
  else if (c != '_' && (c < 65 || (c > 90 && c < 97) || c > 122))
    my_printf(2, "Variable name must begin with a letter.\n");
  else if (e > 1)
    my_printf(2, "Variable name must contain alphanumeric characters.\n");
  return (84);
}

int	my_setenv(char **cmd)
{
  int	i;
  int	len;
  char	*tmp;
  char	**old;

  i = -1;
  if (cmd == NULL)
    return (84);
  while (cmd[++i] != NULL);
  if (i == 1)
    return (r = my_disptab(env));
  if ((my_checksetenv(cmd, i)) == 84)
    return (r = 1);
  if ((my_getenv(tmp = my_scat(cmd[1], "="), &len)) == NULL)
    {
      env = my_tabrealloc((old = env), 1);
      free(old);
    }
  else
    free(env[len]);
  env[len] = (i == 2) ? tmp : my_scat(tmp, cmd[2]);
  if (i == 3)
    free(tmp);
  return (r = 0);
}

char	**my_unsetlen(char **cmd, int *uns)
{
  int	i;
  int	len;

  i = 0;
  (*uns) = 0;
  while (cmd[++i] != NULL)
    if ((my_getenv((cmd[i] = my_scat(cmd[i], "=")), &len)) != NULL)
      --(*uns);
  if (i == 1)
    {
      my_printf(1, "unsetenv: Too few arguments.\n");
      return (NULL);
    }
  ++(*uns);
  return (cmd);
}

int	my_unsetenv(char **c)
{
  int	i;
  int	k;
  int	j;
  char	**new;

  i = -1;
  if ((c = my_unsetlen(c, &k)) == NULL)
    return (r = 1);
  while (env[++i] != NULL);
  if ((new = malloc(sizeof(char *) * (i + k))) == NULL)
    return (84);
  i = (k = -1);
  while (env[++i] != NULL)
    {
      j = 0;
      while (c[++j] != NULL && my_scmp(c[j], env[i], my_strlen(c[j], 0)) != 0);
      if (c[j] == NULL)
	new[++k] = env[i];
      else
	free(env[i]);
    }
  new[++k] = NULL;
  free(env);
  env = new;
  return (r = my_freetab3(c));
}
