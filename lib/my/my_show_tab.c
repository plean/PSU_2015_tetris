/*
** my_show_wordtab.c for wordtab in /home/zeng_d/test/08
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Oct  7 16:59:48 2015 David Zeng
** Last update Mon Jan 18 23:34:13 2016 David Zeng
*/

#include <stdlib.h>
#include "my.h"

void	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
