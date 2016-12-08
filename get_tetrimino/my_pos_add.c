/*
** my_pos_add.c for my_pos_add in /home/zeng_d/rendu/Unix/PSU_2015_my_ls/list
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Nov 17 14:37:05 2015 David Zeng
** Last update Tue Mar 15 20:50:14 2016 David Zeng
*/

#include "my_fonction.h"

int		my_do_pos(t_list *list, void *data, t_node *tmp)
{
  t_node	*node;

  if ((node = malloc(sizeof(*node))) == NULL)
    return (1);
  node->data = data;
  tmp->prev->next = node;
  node->next = tmp;
  node->prev = tmp->prev;
  tmp->prev = node;
  list->length = list->length + 1;
  return (0);
}

int			my_pos_add(t_list *list, void *data, int position)
{
  int			i;
  t_node		*node;

  i = 1;
  if (list == NULL || data == NULL)
    return (1);
  node = list->debut;
  while (i < position && node != NULL)
    {
      node = node->next;
      i = i + 1;
    }
  if (position == 1)
    my_add_first(list, data);
  else if (list->length < position)
    my_add_list(list, data);
  else
    my_do_pos(list, data, node);
  return (0);
}
