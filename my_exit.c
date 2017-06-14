/*
** my_exit.c for my_exit in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Sun Apr 16 00:42:14 2017 SingeSumo
** Last update Fri Apr 21 02:14:06 2017 SingeSumo
*/

# include "my.h"

int	my_freexit(char ***cmd, char *s)
{
  if ((isatty(0)) == 1)
    write(1, "exit\n", 5);
  if (cmd != NULL)
    my_freetab2(cmd);
  if (s != NULL)
    free(s);
  my_freetab(env);
  return (0);
}

int	my_exit(char **cmd)
{
  int	i;
  int	exit;

  i = -1;
  exit = -1;
  while (cmd[++i] != NULL);
  if (i >= 2)
    {
      r = 1;
      if ((i > 2) || ((cmd[1][0] < '0' || cmd[1][0] > '9')))
	my_printf(1, "exit: Expression Syntax.\n");
      else if ((exit = my_isnum(cmd[1])) == 84)
	my_printf(1, "exit: Badly formed number.\n");
      else if (exit == 0)
	r = my_getnbr(cmd[1]);
    }
  if (i == 1)
    r = 0;
  if (i == 1 || exit == 0)
    return (1);
  return (0);
}
