/*
** my_parsing.c for my_parsing in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Sat Apr 15 09:32:46 2017 SingeSumo
** Last update Sat Apr 15 10:37:04 2017 SingeSumo
*/

# include "my.h"

int	my_scount(char *s, char c)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (s[++i] != '\0')
    if (s[i] == c)
      nb++;
  return (++nb);
}

char	***my_separator(char *s)
{
  int	i;
  char	**tmp;
  char	***cmd;

  if (s == NULL)
    return (NULL);
  i = -1;
  tmp = my_wordtab(s, ";");
  while (tmp[++i] != NULL);
  if ((cmd = malloc(sizeof(char **) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while (tmp[++i] != NULL)
    cmd[i] = my_wordtab(tmp[i], " \t");
  cmd[i] = NULL;
  free(tmp);
  return (cmd);
}
