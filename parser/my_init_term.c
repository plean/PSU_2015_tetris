/*
** my_init_term.c for tetris in /home/zeng_d/rendu/Unix/PSU_2015_tetris
**
** Made by David Zeng
** Login   <David@epitech.net>
**
** Started on  Tue Mar  8 18:28:33 2016 David Zeng
** Last update Wed Mar 16 16:38:51 2016 Jean PLANCHER
*/

#include "my_fonction.h"

int			my_init_term(char **env, int mode)
{
  static struct termios	new;
  static struct termios	old;
  char			*tmp;

  if (env != NULL && (tmp = my_get_env(env, "TERM")) == NULL)
    {
      my_printf("Term not found\n");
      return (1);
    }
  if (env != NULL && setupterm(tmp, 1, NULL) == -1)
    return (1);
  if (mode == 0)
    {
      ioctl(0, TCGETS, &new);
      ioctl(0, TCGETS, &old);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      ioctl(0, TCSETS, &new);
    }
  else if (mode == 1)
    ioctl(0, TCSETS, &old);
  return (0);
}

void		ch_read_state(int mode)
{
  static struct	termios	new;
  static struct termios	old;

  if (mode == 0)
    {
      ioctl(0, TCGETS, &new);
      ioctl(0, TCGETS, &old);
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &new);
    }
  else if (mode == 1)
    ioctl(0, TCSETS, &old);
}
