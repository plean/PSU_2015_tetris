/*
** my_putstr.c for putstr in /home/zeng_d/test/Piscine_C_J04
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Oct  1 10:51:31 2015 David Zeng
** Last update Mon Dec 14 22:00:30 2015 David Zeng
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  if (str == NULL)
    {
      write(2, "(null)\n", 7);
      return (-1);
    }
  write(1, str, my_strlen(str));
  return (0);
}
