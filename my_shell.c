/*
** my_42sh.c for my_42sh.c in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Thu Apr 13 04:54:25 2017 SingeSumo
** Last update Fri Apr 21 15:46:58 2017 SingeSumo
*/

# include "my.h"

int	my_builtin(char ***cmd)
{
  int	i;
  int	exit;

  i = -1;
  exit = 0;
  while (cmd[++i] != NULL)
    {
      if ((my_scmp(cmd[i][0], "exit", 5)) == 0)
	exit = my_exit(cmd[i]);
      else if ((my_scmp(cmd[i][0], "setenv", 7)) == 0)
	my_setenv(cmd[i]);
      else if ((my_scmp(cmd[i][0], "unsetenv", 9)) == 0)
	my_unsetenv(cmd[i]);
      else if ((my_scmp(cmd[i][0], "cd", 3)) == 0)
	my_cd(cmd[i]);
      else if (cmd[i][0] != NULL && cmd[i][0][0] != '\0')
	my_command(cmd[i], &cmd[i]);
    }
  if (exit == 1)
    return (84);
  return (0);
}

int	my_shell()
{
  char	*s;
  char	***cmd;

  while ("Nique le coaching")
    {
      if ((isatty(0)) == 1)
	my_prompt();
      if ((cmd = my_separator(s = my_gnl(0))) == NULL)
	return (my_freexit(cmd, s));
      if ((my_builtin(cmd)) == 84)
	return (my_freexit(cmd, s));
      my_freetab2(cmd);
      free(s);
    }
  return (0);
}

void	my_initenv()
{
  int	i;
  int	nb;
  char	*s;

  i = -1;
  r = 0;
  env = my_tabrealloc(env, 0);
  while (env[++i] != NULL)
    env[i] = my_sdup(env[i]);
  if ((my_getenv("SHLVL", &i)) != NULL)
    {
      nb = my_getnbr(env[i] + 6);
      ++nb;
      s = my_nbr(nb);
      free(env[i]);
      env[i] = my_scat("SHLVL=", s);
      free(s);
    }
}

int	main(int ac, unused char **av)
{
  signal(SIGINT, my_ctrlc);
  my_initenv();
  if (ac != 1 || (my_shell()) == 84)
    return (84);
  return (r);
}
