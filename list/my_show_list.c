/*
** my_show_list.c for show list in /home/zeng_d/test/fonctions
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Oct 20 16:34:50 2015 David Zeng
** Last update Mon Dec 14 15:53:37 2015 David Zeng
*/

#include <stdlib.h>
#include "my_list.h"
#include "my.h"

void		my_show_list(t_list *list)
{
  t_node	*tmp;

  tmp = list->debut;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putchar(' ');
      tmp = tmp->next;
    }
}
