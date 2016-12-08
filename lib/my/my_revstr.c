/*
** my_revstr.c for revstr in /home/zeng_d/test/06
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Oct  5 11:46:49 2015 David Zeng
** Last update Mon Jan 18 23:27:08 2016 David Zeng
*/

#include <stdlib.h>
#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	a;
  char	tmp;

  if (str == NULL)
    return (NULL);
  i = my_strlen(str) - 1;
  a = 0;
  while (a < i)
    {
      tmp = str[a];
      str[a] = str[i];
      str[i] = tmp;
      a = a + 1;
      i = i - 1;
    }
  return (str);
}
