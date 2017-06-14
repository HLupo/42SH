/*
** my_free.c for my_free in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Mon Apr 17 09:30:14 2017 SingeSumo
** Last update Thu Apr 20 23:13:03 2017 SingeSumo
*/

# include "my.h"

int	my_freetab3(char **tab)
{
  int	i;

  i = 0;
  while (tab[++i] != NULL)
    free(tab[i]);
  return (0);
}

int	my_freetab2(char ***tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
  return (0);
}

int	my_freetab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
  return (0);
}
