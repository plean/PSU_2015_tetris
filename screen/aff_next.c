/*
** aff_next.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 15 23:23:59 2016 Jean PLANCHER
** Last update Mon Mar 21 22:17:14 2016 Jean PLANCHER
*/

#include "screen.h"

static t_mino	*copie_tetrimino(t_list *tetriminos,
				 t_setup *setup,
				 t_screen *win)
{
  t_node	*elem;
  t_mino	*data;
  t_mino	*tmp;

  if ((data = malloc(sizeof(t_mino))) == NULL)
      return (NULL);
  setup->new_tet = 1;
  elem = tetriminos->debut;
  while (--setup->aff_next > 0)
    elem = elem->next;
  tmp = (t_mino *)elem->data;
  win->x = (setup->width - tmp->width) / 2;
  win->y = 0;
  data->height = tmp->height;
  data->width = tmp->width;
  data->color = tmp->color;
  if ((data->shape = malloc(sizeof(char) * (data->width * data->height))) == NULL)
    return (NULL);
  setup->aff_next--;
  while (tmp->shape[++setup->aff_next])
    data->shape[setup->aff_next] = tmp->shape[setup->aff_next];
  data->shape[setup->aff_next] = 0;
  setup->aff_next = rand() % tetriminos->length + 1;
  return (data);
}

void		aff_next(t_screen *win, t_setup *setup, t_list *tetriminos)
{
  t_mino	*mino;
  t_node	*elem;
  int		color;
  int		i;

  elem = tetriminos->debut;
  if (setup->new_tet == 0)
    win->actual = copie_tetrimino(tetriminos, setup, win);
  win->is_ended = (my_move(win, setup)) ? 1 : 0;
  if (setup->next == true && (i = 1))
    {
      while (i++ < setup->aff_next)
	elem = elem->next;
      mino = (t_mino *)elem->data;
      i = -1;
      color = (mino->color < 8 && mino->color > 0) ? mino->color : 0;
      while (mino->shape[++i])
	if (mino->shape[i] == '*')
	    {
	      wattron(win->next, COLOR_PAIR(color));
	      mvwprintw(win->next, i / mino->width + 1, i % mino->width * 2 + 1, "  ");
	      wattroff(win->next, COLOR_PAIR(color));
	    }
    }
}
