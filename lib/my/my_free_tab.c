/*
** my_free_tab.c for free_tab in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 02:33:02 2016 David Zeng
** Last update Mon Jan 18 23:25:29 2016 David Zeng
*/

#include <stdlib.h>

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return;
  while (tab[i] != 0)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}
