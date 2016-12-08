/*
** my_strndup.c for strndup in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan  6 01:02:29 2016 David Zeng
** Last update Mon Jan 18 23:30:59 2016 David Zeng
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(char *str, int nb)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (nb + 1))) == NULL || str == NULL)
    return (NULL);
  my_strncpy(new, str, nb);
  return (new);
}
