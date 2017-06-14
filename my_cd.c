/*
** my_cd.c for my_cd in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Mon Apr 17 09:39:43 2017 SingeSumo
** Last update Fri Apr 21 19:49:02 2017 SingeSumo
*/

# include "my.h"

int	my_cdarg(char *s)
{
  int	i;

  if (s == NULL)
    return (0);
  i = -1;
  while (s[++i] != '\0')
    if (s[i] != '-')
      return (-1);
  return (i);
}

int	my_setcd(char *var)
{
  int	i;
  char	*s1;
  char	*s2;
  char	**tab;

  if ((my_getenv(var, &i)) != NULL)
    {
      free(env[i]);
      env[i] = (s1 = my_scat(var, "="));
      env[i] = my_scat(env[i], (s2 = getcwd(NULL, 50)));
      free(s1);
      free(s2);
      return (0);
    }
  s1 = ((my_scmp(var, "PWD", 3)) == 0) ? "setenv PWD " : "setenv OLDPWD ";
  s1 = my_scat(s1, (s2 = getcwd(NULL, 50)));
  free(s2);
  my_setenv(tab = my_wordtab(s1, " "));
  free(s1);
  free(tab);
  return (0);
}

int	my_cdhome()
{
  int	i;
  char	*home;

  r = 0;
  home = my_getenv("HOME", &i);
  home += (home != NULL) ? 5 : 0;
  if (home != NULL)
    {
      my_setcd("OLDPWD");
      chdir(home);
    }
  else
    my_printf(2, "HOME: Undefined variable.\n");
  return (0);
}

int	my_cdless()
{
  int	pwd;
  int	oldpwd;
  char	*s;

  r = 0;
  my_getenv("PWD", &pwd);
  my_getenv("OLDPWD", &oldpwd);
  if (env[pwd] != NULL && env[oldpwd] != NULL)
    {
      s = my_scat("OLD", env[pwd]);
      chdir(env[oldpwd] + 7);
      free(env[oldpwd]);
      env[oldpwd] = s;
    }
  if (env[oldpwd])
    chdir(env[oldpwd]);
  else if (env[pwd] == NULL && env[oldpwd] == NULL)
    my_printf(2, "PWD & OLDPWD: Undefined variables.\n");
  else if (env[pwd] == NULL)
    my_printf(2, "PWD: Undefined variable.\n");
  else if (env[oldpwd] == NULL)
    my_printf(2, "OLDPWD: Undefined variable.\n");
  return (0);
}

int	my_cd(char **cmd)
{
  int	i;
  int	a1;
  int	a2;

  i = -1;
  errno = 0;
  a2 = ((a1 = my_cdarg(cmd[1])) != 0) ? my_cdarg(cmd[2]) : 0;
  while (cmd[++i] != NULL);
  if ((a1 == 1 && a2 < 0) || i > 3 || (i == 3 && (a1 != 2 && a1 != 1)))
    my_cderror(cmd[0], a1, a2, i);
  else if (a1 == 1 && a2 >= 0)
    my_cdless();
  else if (i == 1 || (i == 2 && a1 == 2))
    my_cdhome();
  else if ((my_setcd("OLDPWD")) == 0 && (chdir(cmd[i - 1])) == -1)
    my_cderror(cmd[i - 1], a1, a2, i);
  my_setcd("PWD");
  return (0);
}
