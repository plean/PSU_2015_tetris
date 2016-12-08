/*
** my_add_list.c for toto in /home/zeng_d/usefull/my_lib/source/list
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Oct 22 15:31:42 2015 David Zeng
** Last update Tue Mar 15 20:54:09 2016 David Zeng
*/

#include "my_fonction.h"

int             my_add_list(t_list *list, void *data)
{
  t_node        *node;

  node = malloc(sizeof(t_node));
  if (list == NULL || node == NULL)
    return (1);
  node->data = data;
  node->prev = list->fin;
  node->next = NULL;
  if (list->fin != NULL)
    list->fin->next = node;
  else
    list->debut = node;
  list->fin = node;
  list->length = list->length + 1;
  return (0);
}
