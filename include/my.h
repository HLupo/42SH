/*
** my.h for my.h in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh/include
** 
** Made by SingeSumo
** Login   <SingeSumo@epitech.net>
** 
** Started on  Tue Apr 11 22:52:49 2017 SingeSumo
** Last update Fri Apr 21 20:07:34 2017 SingeSumo
*/

#ifndef MY_H_
# define MY_H_

# define _GNU_SOURCE
# define env environ
# define unused __attribute__((unused))
# define basicpath "usr/local/bin:/usr/bin:/bin:/usr/games"	\

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <dirent.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/resource.h>

/*	Global		*/
int	r;

/*	GNL		*/
char	*my_gnl(const int);
char	*my_file(char *, int *);

/*	Wordtab		*/
int	my_isalpha(char *);
char	*my_scat(char *, char *);
char	**my_wordtab(char *, char *);
int	my_setsep(char **, char *, int);

/*	Disp		*/
char	*my_nbr(int);
int	my_getnbr(char *);
int	my_write(int, char *, int);
int	my_printf(int, char *, ...);
int	my_sorter(int, char, va_list);

/*	Utils		*/
int	my_pow(int, int);
int	my_isnum(char *);
char	*my_revstr(char *);
int	my_strlen(char *, char);
int	my_scmp(char *, char *, int);

/*	Env		*/
int	my_setenv(char **);
int	my_unsetenv(char **);
int	my_badsetenv(int, int);
char	*my_getenv(char *, int *);

/*	Alloc		*/
char	**my_lscolors(char **);
char	*my_sdup(char *);
char	**my_tabrealloc(char **, int);

/*	Free		*/
int	my_freetab(char **);
int	my_freetab3(char **);
int	my_freetab2(char ***);

/*	Exit		*/
int	my_exit(char **);
int	my_freexit(char ***, char *);

/*	Ctrl		*/
void	my_ctrlc();

/*	Prompt		*/
int	my_prompt();
int	my_is_git();
int	my_disptab(char **);
int	my_disptabtab(char ***);

/*	Error		*/
int	my_cderror(char *, int, int, int);
int	my_execerror(int);

/*	Parsing		*/
int	my_scount(char *, char);
char	***my_separator(char *);

/*	Cd		*/
int	my_cd(char **);

/*	Echo		*/
void	my_echo(char **, char **);

/*	Exec		*/
int	my_command(char **, char ***);

#endif /* !MY_H_ */
