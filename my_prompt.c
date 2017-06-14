/*
** my_prompt.c for my_prompt in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Thu Apr 13 21:53:51 2017 SingeSumo
** Last update Tue Apr 18 08:18:22 2017 SingeSumo
*/

# include "my.h"

int	my_disptab(char **tab)
{
  int	i;

  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    my_printf(1, "%s\n", tab[i]);
  return (0);
}

int	my_disptabtab(char ***tab)
{
  int	i;

  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    {
      my_disptab(tab[i]);
      my_printf(1, "###\n");
    }
  return (0);
}

int	my_is_git()
{
  int	fd;
  char	s[7];

  if ((fd = open(".git/HEAD", O_RDONLY)) == -1)
    return (0);
  my_printf(1, "\033[1;34mgit:(\033[1;31m");
  if ((read(fd, s, 7)) == -1)
    return (0);
  s[7] = '\0';
  if ((my_scmp(s, "ref: ", 4)) == 0)
    my_printf(1, "master\033[1;34m) ", s);
  else
    my_printf(1, "%s\033[1;34m) ", s);
  return (0);
}

int	my_is_home(char *s, int i)
{
  int	l;
  char	*home;

  home = my_getenv("HOME", &l);
  home += (home != NULL) ? 5 : 0;
  if ((my_scmp(s, home, (my_strlen(s, 0) + 1))) == 0)
    my_printf(1, "\033[1;36m~ ", (s + i));
  else
    my_printf(1, "\033[1;36m%s ", (s + i));
  return (0);
}

int	my_prompt()
{
  int	i;
  char	*s;

  s = (r == 0) ? "\033[1;32m" : "\033[1;31m";
  my_printf(1, "%s➜  \033[0m", s);
  if ((s = getcwd(NULL, 100)) == NULL)
    return (0);
  i = -1;
  while (s[++i] != '\0');
  while (s[--i] != '/');
  ((my_strlen((s + i + 1), '\0')) == 0) ? i : ++i;
  my_is_home(s, i);
  my_is_git();
  my_printf(1, "\033[0m");
  free(s);
  return (0);
}
