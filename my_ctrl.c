/*
** my_ctrlc.c for my_ctrlc in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Sat Apr 15 10:18:45 2017 SingeSumo
** Last update Sun Apr 16 23:31:07 2017 SingeSumo
*/

# include "my.h"

void	my_ctrlc()
{
  r = 1;
  write(1, "\n", 1);
  my_prompt();
}
