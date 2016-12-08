/*
** my_strncpy.c for strncpy in /home/zeng_d/test/06
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Oct  5 10:03:28 2015 David Zeng
** Last update Mon Jan 18 23:32:49 2016 David Zeng
*/

#include <stdlib.h>

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] != 0 && i < nb)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
