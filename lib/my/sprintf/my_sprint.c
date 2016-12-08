/*
** my_print.c for prin in /home/zeng_d/rendu/Unix/PSU_2015_my_printf_bootstrap
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Nov  5 16:50:56 2015 David Zeng
** Last update Wed Feb 17 21:19:16 2016 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	my_sprintc(va_list list, char *buffer)
{
  my_sputchar(buffer, va_arg(list, int));
  return (1);
}

int	my_sprints(va_list list, char *buffer)
{
  char	*str;

  str = va_arg(list, char *);
  my_sputstr(buffer, str);
  return (my_strlen(str));
}

int	my_sprinti(va_list list, char *buffer)
{
  int	tmp;
  int	nb;
  int	flag;

  tmp = va_arg(list, int);
  nb = (tmp < 0) ? 1 : 0;
  flag = nb;
  my_sput_nbr(buffer, tmp);
  if (tmp < 0)
    tmp = - tmp;
  while (tmp > 0)
    {
      tmp = tmp / 10;
      nb = nb + 1;
    }
  buffer[nb] = 0;
  my_revstr(&buffer[flag]);
  return (nb);
}
