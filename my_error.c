/*
** my_error.c for my_error.c in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Fri Apr 21 02:04:43 2017 SingeSumo
** Last update Fri Apr 21 11:54:05 2017 SingeSumo
*/

# include "my.h"

int	my_cderror(char *cmd, int a1, int a2, int i)
{
  r = 1;
  if (a1 == 1 && a2 < 0)
    my_printf(2, "Usage: cd [-plvn][-|<dir>].\n");
  else if (i > 3 || (i == 3 && (a1 != 2)))
    my_printf(2, "cd: Too many arguments.\n");
  else if (errno == EACCES)
    my_printf(2, "%s: Permission denied.\n", cmd);
  else if (errno == ENOTDIR)
    my_printf(2, "%s: Not a directory.\n", cmd);
  else if (errno == ENOENT)
    my_printf(2, "%s: No such file or directory.\n", cmd);
  return (0);
}

int	my_execerror(int pid)
{
  int	sig;

  waitpid(pid, &sig, 0);
  if (WIFEXITED(sig))
    return  (WEXITSTATUS(sig));
  if (WTERMSIG(sig) == 11 || WTERMSIG(sig) == 6 || WTERMSIG(sig) == SIGFPE)
    {
      if (WTERMSIG(sig) == SIGFPE)
	my_printf(2, "Floating exception");
      if (WTERMSIG(sig) == 11)
	my_printf(2, "Segmentation fault");
      if (WTERMSIG(sig) == 6)
	my_printf(2, "Abort");
      if (WCOREDUMP(sig))
	my_printf(2, " (core dumped)");
      my_printf(2, "\n");
      sig = 128 + WTERMSIG(sig);
    }
  else if (WIFSIGNALED(sig))
    {
      sig = 128 + WTERMSIG(sig);
      my_printf(2, "Terminated by signal : %d\n", sig);
    }
  return (sig);
}
