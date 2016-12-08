/*
** my_printS.c for print S in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov  9 01:17:59 2015 David Zeng
** Last update Wed Feb 17 04:24:28 2016 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int		my_sget_oct(unsigned char nb)
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

void		my_sput_S(unsigned char c, char *buffer)
{
  int		oct;

  oct = my_sget_oct(c);
  my_sputchar(buffer, '\\');
  if (oct < 10)
    my_sputchar(&buffer[1], '0');
  if (oct >= 10 && oct < 100)
    my_sputchar(&buffer[1], '0');
  else if (oct < 100)
    my_sputchar(&buffer[2], '0');
  my_sput_nbr(buffer, oct);
}

int		my_sprintS(va_list list, char *buffer)
{
  int		i;
  unsigned char	*str;

  i = 0;
  str = va_arg(list, unsigned char*);
  while (str[i] != '\0')
    {
      while (str[i] > 31 && str[i] < 127)
	{
	  my_sputchar(buffer, str[i]);
	  i = i + 1;
	}
      if (str[i] == '\0')
	return (0);
      my_sput_S(str[i], buffer);
      i = i + 1;
    }
  return (0);
}
