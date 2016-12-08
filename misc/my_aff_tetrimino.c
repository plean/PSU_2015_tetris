/*
** my_aff_tetrimino.c for tetris in /home/zeng_d/.emacs.d/private/tabbar
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar  4 18:44:18 2016 David Zeng
** Last update Wed Mar  9 01:43:21 2016 David Zeng
*/

#include "my_fonction.h"

int		my_check_end_space(t_pos *pos, int width, char *shape)
{
  int		x;

  if (shape[pos->y * width + pos->x] != ' ')
    return (1);
  x = width - 1;
  while (x != pos->x && shape[pos->y * width + x] == ' ')
    x = x - 1;
  if (x == pos->x)
    return (0);
  return (1);
}

void		my_aff_mino(t_mino *tmp)
{
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  my_printf("Tetriminos : Name %s : ", tmp->name);
  if (tmp->error == true)
    {
      my_printf("Error\n");
      return;
    }
  my_printf("Size %d*%d : Color %d :\n", tmp->width, tmp->height, tmp->color);
  while (pos.y < tmp->height)
    {
      while (pos.x < tmp->width)
	{
	  if (my_check_end_space(&pos, tmp->width, tmp->shape) == 1)
	    my_putchar(tmp->shape[pos.y * tmp->width + pos.x]);
	  pos.x += 1;
	}
      my_putchar('\n');
      pos.x = 0;
      pos.y += 1;
    }
}

void		my_aff_tetrimino(t_list *tetrimino)
{
  t_node	*tmp;

  if (tetrimino == NULL)
    return;
  tmp = tetrimino->debut;
  my_printf("Tetriminos : %d\n", tetrimino->length);
  while (tmp != NULL)
    {
      my_aff_mino(tmp->data);
      tmp = tmp->next;
    }
}
