/*
** my_utils.c for my_power_rec.c in /home/SingeSumo/CPE/CPE_2016_Pushswap
** 
** Made by Nathan Quesseveur-Julien
** Login   <SingeSumo@epitech.net>
** 
** Started on  Mon Nov 21 07:53:06 2016 Nathan Quesseveur-Julien
** Last update Mon Apr 17 04:12:33 2017 SingeSumo
*/

# include "my.h"

int	my_strlen(char *str, char c)
{
  int	len;

  len = 0;
  if (str == NULL)
    return (-1);
  while (str[len] != c)
    len++;
  return (len);
}

int	my_isnum(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (84);
  while (str[++i] != '\0')
    if (str[i] < '0' || str[i] > '9')
      return (84);
  return (0);
}

int	my_pow(int nb, int p)
{
  if (p == 0)
    return (1);
  if (p > 1)
    {
      p = p - 1;
      nb *= my_pow(nb, p);
    }
  return (nb);
}

char	*my_revstr(char *str)
{
  int	a;
  int	b;
  int	c;

  if (str == NULL)
    return (NULL);
  b = 0;
  a = my_strlen(str, '\0') - 1;
  while (a > b)
    {
      c = str[b];
      str[b] = str[a];
      str[a] = c;
      b = b + 1;
      a = a - 1;
    }
  return (str);
}

int	my_scmp(char *s1, char *s2, int n)
{
  int	i;
  int	l1;
  int	l2;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-2);
  l1 = my_strlen(s1, '\0');
  l2 = my_strlen(s2, '\0');
  while (l1 != i && l2 != i && s1[i] == s2[i] && i < n)
    i++;
  if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    return (0);
  else if ((s1[i] > s2[i] && l1 == l2) || l1 > l2)
    return (1);
  else
    return (-1);
}
