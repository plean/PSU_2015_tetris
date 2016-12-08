/*
** my_tablen.c for tablen in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan  6 23:46:23 2016 David Zeng
** Last update Mon Jan 18 23:31:15 2016 David Zeng
*/

#include <stdlib.h>

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (-1);
  while (tab[i] != 0)
    {
      i = i + 1;
    }
  return (i);
}
