/*
** my_mino_max_length.c for my_mino_max_length in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar 15 20:50:34 2016 David Zeng
** Last update Wed Mar 16 02:23:32 2016 David Zeng
*/

#include "my_fonction.h"

void			my_mino_max_length(t_list *list)
{
  t_mino		*mino;
  t_node		*node;

  node = list->debut;
  while (node != NULL)
    {
      mino = node->data;
      if (mino->width > list->max_w)
	list->max_w = mino->width;
      if (mino->height > list->max_h)
	list->max_h = mino->height;
      node = node->next;
    }
}
