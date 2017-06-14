/*
** my_alloc.c for my_alloc in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Mon Apr 17 05:02:57 2017 SingeSumo
** Last update Fri Apr 21 02:07:24 2017 SingeSumo
*/

# include "my.h"

char	**my_tabrealloc(char **tab, int add)
{
  int	i;
  int	len;
  char	**res;

  len = -1;
  while (tab[++len] != NULL);
  if ((res = malloc(sizeof(char *) * (len + add + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < (len + add + 1))
    res[i] = (i < len && tab[i] != NULL) ? tab[i] : NULL;
  return (res);
}

char	*my_sdup(char *s)
{
  int	i;
  char	*new;

  i = -1;
  if ((new = malloc(sizeof(char) * (my_strlen(s, '\0') + 1))) == NULL)
    return (NULL);
  while (s[++i] != '\0')
    new[i] = s[i];
  new[i] = '\0';
  return (new);
}
