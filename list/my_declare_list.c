/*
** my_declare_list.c for declare list in /home/zeng_d/test/fonctions
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Oct 20 15:46:26 2015 David Zeng
** Last update Tue Mar 15 20:39:40 2016 David Zeng
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"

t_list		*my_declare_list()
{
  t_list	*list;

  list = malloc(sizeof(*list));
  if (list == NULL)
    return (NULL);
  list->length = 0;
  list->debut = NULL;
  list->fin = NULL;
  list->max_h = 0;
  list->max_w = 0;
  return (list);
}
