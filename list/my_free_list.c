/*
** my_free_list.c for my_free_list in /home/zeng_d/rendu/Unix/PSU_2015_my_ls/list
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Nov 17 22:57:50 2015 David Zeng
** Last update Mon Dec 14 15:53:26 2015 David Zeng
*/

#include <stdlib.h>
#include "my_list.h"

void		my_free_list(t_list **list)
{
  t_node	*tmp;
  t_node	*node;

  if (list == NULL)
    return;
  node = (*list)->debut;
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      free(tmp);
    }
  free(*list);
  *list = NULL;
}
