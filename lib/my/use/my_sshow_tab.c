/*
** my_sshow_tab.c for sprintf in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Feb 17 03:29:13 2016 David Zeng
** Last update Wed Feb 17 03:36:49 2016 David Zeng
*/

#include "my.h"
#include <unistd.h>

void		my_sshow_tab(char *buffer, char **tab)
{
  if (tab == NULL || *tab == NULL)
    return;
  my_sputstr(buffer, *tab);
  my_sputchar(buffer, '\n');
  my_sshow_tab(&buffer[my_strlen(*tab)], &tab[1]);
}
