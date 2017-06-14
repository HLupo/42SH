/*
** get_next_line.c for get_next_line in /home/SingeSumo/Epitech/CPE/CPE_2016_getnextline
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Wed Jan  4 17:19:13 2017 SingeSumo
** Last update Thu Apr 13 07:18:52 2017 SingeSumo
*/

# include "my.h"

char	*my_file(char *path, int *i)
{
  char	buff[4096];
  char	*str;
  int	size;
  int	fd;
  int	fp;

  if ((fd = open(path, O_RDONLY)) == -1 || (fp = open(path, O_RDONLY)) == -1)
    return (NULL);
  if (*i == -1)
    free(path);
  *i = 0;
  while ((size = read(fd, buff, 4096)) >= 4096)
    *i += size;
  *i += size;
  if (size == -1)
    return (NULL);
  if ((str = malloc(sizeof(char) * (*i + 1))) == NULL)
    return (NULL);
  if ((read(fp, str, *i)) == -1)
    return (NULL);
  str[*i] = '\0';
  if ((close(fd)) == -1 || (close(fp)) == -1)
    return (NULL);
  return (str);
}

char		*my_gnl(const int fd)
{
  int		i;
  static int	size;
  static int	pos = -1;
  static char	buff[4096];
  char		*str;

  if ((fd < 0) || (pos == -1 && (size = read(fd, buff, 4096)) <= 0))
    return (NULL);
  i = pos;
  while (buff[++i] != '\0' && buff[i] != '\n');
  if ((str = malloc(sizeof(char) * (i - pos))) == NULL)
    return (NULL);
  i = -1;
  while (++pos < (size - 1) && buff[pos] != '\n')
    str[++i] = buff[pos];
  str[++i] = '\0';
  if (pos >= (size - 1))
    pos = -1;
  return (str);
}
