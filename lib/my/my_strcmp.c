/*
** my_strcmp.c for strcmp in /home/zeng_d/test/06
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Oct  5 16:33:06 2015 David Zeng
** Last update Mon Jan 18 23:32:11 2016 David Zeng
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && s1[i] != '\0')
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
