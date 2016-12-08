/*
** my_strcat.c for strcat in /home/zeng_d/test/07
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Oct  6 17:25:11 2015 David Zeng
** Last update Mon Jan 18 23:31:41 2016 David Zeng
*/

#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
