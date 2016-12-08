/*
** my_printS.c for print S in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov  9 01:17:59 2015 David Zeng
** Last update Sun Dec 27 17:08:28 2015 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int		my_get_oct(unsigned char nb)
{
  int		i;
  int		oct;

  oct = 0;
  i = 1;
  while (nb > 0)
    {
      oct = oct + (nb % 8) * i;
      nb = nb / 8;
      i = i * 10;
    }
  return (oct);
}

void		my_put_S(unsigned char c, int *n)
{
  int		oct;

  oct = my_get_oct(c);
  my_putchar('\\');
  if (oct < 10)
    my_putchar('0');
  if (oct < 100)
    my_putchar('0');
  my_put_nbr(oct);
  *n = *n + 3;
}

int		my_printS(va_list list, int *n)
{
  int		i;
  unsigned char	*str;

  i = 0;
  str = va_arg(list, unsigned char*);
  if (str == NULL)
    {
      my_putstr("(null)");
      *n = *n + 6;
      return (0);
    }
  *n = *n + my_strlen((char*)str);
  while (str[i] != '\0')
    {
      while (str[i] > 31 && str[i] < 127)
	{
	  my_putchar(str[i]);
	  i = i + 1;
	}
      if (str[i] == '\0')
	return (0);
      my_put_S(str[i], n);
      i = i + 1;
    }
  return (0);
}
