/*
** my_strcpy.c for  in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan  4 22:01:12 2016 David Zeng
** Last update Mon Jan 18 23:33:41 2016 David Zeng
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
