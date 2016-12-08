/*
** my_strdup.c for strdup in /home/zeng_d/test/08
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Oct  7 14:41:59 2015 David Zeng
** Last update Mon Jan 18 23:29:12 2016 David Zeng
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*str;

  i = 0;
  if ((str = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL ||
      src == NULL)
    return (NULL);
  while (i < my_strlen(src))
    {
      str[i] = src[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}
