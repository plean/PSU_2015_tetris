/*
** my_sort_add.c for sort add in /home/zeng_d/rendu/Unix/PSU_2015_my_ls
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Nov 17 16:58:38 2015 David Zeng
** Last update Tue Mar  1 21:57:46 2016 David Zeng
*/

#include "my_fonction.h"
#include <stdlib.h>

void		my_sort_add(t_list *list, void *data)
{
  int		i;
  t_node	*node;

  i = 1;
  if (list == NULL || data == NULL)
    return;
  node = list->debut;
  if (list->debut == NULL)
    {
      my_add_first(list, data);
      return;
    }
  while (node->next != NULL &&
	 my_strcmp(((t_mino *)node->data)->name, ((t_mino*)data)->name) <= 0)
    {
      node = node->next;
      i = i + 1;
    }
  if (my_strcmp(((t_mino*)node->data)->name, ((t_mino*)data)->name) > 0)
    my_pos_add(list, data, i);
  else
    my_pos_add(list, data, i + 1);
}
