/*
** my_strlen.c for strlen in /home/zeng_d/test/Piscine_C_J04
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Oct  1 11:18:27 2015 David Zeng
** Last update Mon Jan 18 23:32:33 2016 David Zeng
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
