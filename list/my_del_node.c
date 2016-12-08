/*
** my_del_node.c for del node in /home/zeng_d/test/tmp
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Nov  3 14:04:04 2015 David Zeng
** Last update Wed Mar 16 02:30:10 2016 David Zeng
*/

#include <stdlib.h>
#include "my_list.h"

int		my_del_node(t_list *list, t_node *node)
{
  t_node	*tmp;

  tmp = node;
  if (list->debut == NULL)
    return (0);
  list->length = list->length - 1;
  if (tmp->next == NULL)
    {
      list->fin = tmp->prev;
      if (tmp->prev != NULL)
      tmp->prev->next = NULL;
    }
  if (tmp->prev == NULL)
    {
      list->debut = tmp->next;
      if (tmp->next != NULL)
	tmp->next->prev = NULL;
    }
  if (tmp->prev != NULL && tmp->next != NULL)
    {
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
    }
  free(tmp);
  return (0);
}
