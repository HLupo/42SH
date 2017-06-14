/*
** my_printf.c for my_printf.c in /home/SingeSumo/PSU/PSU_2016_my_printf
** 
** Made by Nathan Quesseveur-Julien
** Login   <SingeSumo@epitech.net>
** 
** Started on  Fri Nov 11 21:57:32 2016 Nathan Quesseveur-Julien
** Last update Sat Apr 15 16:32:10 2017 SingeSumo
*/

# include "my.h"

int		my_getnbr(char *s)
{
  int		i;
  int		res;
  int		sign;
  int		power;

  i = -1;
  res = 0;
  sign = 0;
  if (s == NULL || s[0] == '\0')
    return (-1);
  while (s[++i] == '+' || s[i] == '-')
    if (s[i] == '-')
      sign++;
  sign = ((((5 * sign) % 10) / 5) * (-2)) + 1;
  power = (my_strlen(s, '\0') - i) - 1;
  while (s[i] != '\0')
    res = (((s[i++] - 48) * sign) * (my_pow(10, power--))) + res;
  return (res);
}

int		my_write(int fd, char *c, int len)
{
  if (c == NULL)
    c = "(null)";
  len = (len == 0) ? my_strlen(c, '\0') : len;
  if ((len = write(fd, c, len)) == -1)
    write(2, "Write have failed\n", 18);
  if (len == -1)
    return (84);
  return (0);
}

char		*my_nbr(int nb)
{
  int		x;
  int		p;
  int		l;
  char		*c;

  p = 0;
  x = nb;
  while (x != 0 && ++p)
    x /= 10;
  l = (nb <= 0) ? 2 : 1;
  if ((c = malloc(sizeof(char) * (p + l))) == NULL)
    return (NULL);
  x = -1;
  (nb < 0) ? c[++x] = '-', nb = -nb : (nb == 0) ? c[++x] = '0' : 0;
  while (p != 0)
    {
      l = my_pow(10, --p);
      c[++x] = (l == 0) ? '0' : (nb / l) + 48;
      nb %= l;
    }
  c[++x] = '\0';
  return (c);
}

int		my_sorter(int fd, char c, va_list a)
{
  int		nb;
  char		*type;

  nb = 0;
  type = "dsc";
  while (c != type[nb] && nb < 3 && ++nb);
  type = (nb < 1) ? my_nbr(va_arg(a, int)) : (nb < 2) ? va_arg(a, char *) : 0;
  c = (nb == 2) ? va_arg(a, int) : c;
  if (nb < 2)
    fd = my_write(fd, type, 0);
  else
    fd = my_write(fd, &c, 1);
  if (nb == 0)
    free(type);
  return (fd);
}

int		my_printf(int fd, char *str, ...)
{
  va_list	args;
  int		i;

  i = -1;
  va_start(args, str);
  while (str[++i] != '\0')
    {
      if ((str[i] != '%') && ((my_write(fd, &str[i], 1)) >= 84))
	return (84);
      if ((str[i] == '%') && ((my_sorter(fd, str[++i], args)) >= 84))
	return (84);
    }
  va_end(args);
  return (0);
}
