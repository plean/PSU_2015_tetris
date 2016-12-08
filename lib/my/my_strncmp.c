/*
** my_strncmp.c for strcmp in /home/zeng_d/test/06
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Oct  5 17:11:21 2015 David Zeng
** Last update Wed Feb 17 23:56:35 2016 David Zeng
*/

#include <stdlib.h>

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && i < nb)
    {
      i = i + 1;
    }
  if (i == nb)
    return (0);
  return (s1[i] - s2[i]);
}
