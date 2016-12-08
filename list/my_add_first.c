/*
** my_add_first.c for my_add_first in /home/zeng_d/test/CPE/pushswap/list
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Nov  3 14:39:27 2015 David Zeng
** Last update Mon Dec 14 15:52:58 2015 David Zeng
*/

#include <stdlib.h>
#include "my_list.h"

int		my_add_first(t_list *list, void *data)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  if (list == NULL || node == NULL)
    return (1);
  node->data = data;
  node->prev = NULL;
  node->next = list->debut;
  if (list->debut != NULL)
    list->debut->prev = node;
  else
    list->fin = node;
  list->debut = node;
  list->length = list->length + 1;
  return (0);
}
