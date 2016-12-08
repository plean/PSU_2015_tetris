/*
** my_print.c for prin in /home/zeng_d/rendu/Unix/PSU_2015_my_printf_bootstrap
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Nov  5 16:50:56 2015 David Zeng
** Last update Mon Dec 14 18:22:28 2015 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	my_printc(va_list list, int *n)
{
  my_putchar(va_arg(list, int));
  *n = *n + 1;
  return (0);
}

int	my_prints(va_list list, int *n)
{
  char	*str;

  str = va_arg(list, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      *n = *n + 6;
      return (0);
    }
  my_putstr(str);
  *n = *n + my_strlen(str);
  return (0);
}

int	my_printi(va_list list, int *n)
{
  int	tmp;

  tmp = va_arg(list, int);
  my_put_nbr(tmp);
  if (tmp < 0)
    *n = *n + 1;
  if (tmp == 0)
    *n = *n + 1;
  while (tmp != 0)
    {
      tmp = tmp / 10;
      *n = *n + 1;
    }
  return (0);
}
