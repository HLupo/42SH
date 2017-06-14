/*
** my_wordtab.c for my_wordtab in /home/SingeSumo/Epitech/Test
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Thu Apr  6 18:35:17 2017 SingeSumo
** Last update Mon Apr 17 06:09:09 2017 SingeSumo
*/

# include "my.h"

int	my_isalpha(char *s)
{
  int	i;
  int	j;
  char	c;

  i = -1;
  j = 122;
  while ((c = s[++i]) != '\0')
    if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97 && c != 95) || c > j)
      return ((i + 1));
  return (0);
}

char	*my_scat(char *s1, char *s2)
{
  int	i;
  int	k;
  char	*s;

  if (s1 == NULL || s2 == NULL)
    return (NULL);
  i = (my_strlen(s1, '\0') + my_strlen(s2, '\0') + 1);
  if ((s = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = -1;
  k = -1;
  while (s1[++i] != '\0')
    s[i] = s1[i];
  while (s2[++k] != '\0')
    s[i++] = s2[k];
  s[i] = '\0';
  return (s);
}

int	my_setsep(char **s, char *c, int len)
{
  int	y;
  int	x;
  int	nb;

  y = (nb = 0) - 1;
  while (c[++y] != '\0')
    {
      x = -1;
      while (++x < len)
	if ((*s)[x] == c[y])
	  {
	    nb++;
	    (*s)[x] = '\0';
	  }
    }
  return (nb);
}

char	**my_wordtab(char *s, char *c)
{
  int	x;
  int	len;
  char	**tab;

  if (s == NULL || c == NULL)
    return (NULL);
  x = -1;
  while (s[++x] != '\0' && (s[x] == ' ' || s[x] == '\t'));
  s += x;
  len = my_strlen(s, '\0');
  x = my_setsep(&s, c, len);
  if ((tab = malloc(sizeof(char *) * (x + 2))) == NULL)
    return (NULL);
  len = -1;
  while (++len <= x)
    {
      tab[len] = s;
      s += (my_strlen(s, '\0') + 1);
      while (x > len && s[0] == '\0' && --x)
	s += 1;
    }
  tab[len] = NULL;
  return (tab);
}
