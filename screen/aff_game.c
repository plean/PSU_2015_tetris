/*
** aff_game.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 16 22:42:38 2016 Jean PLANCHER
** Last update Mon Mar 21 21:37:26 2016 Jean PLANCHER
*/

#include "screen.h"

int	my_move(t_screen *win, t_setup *setup)
{
  int	i;

  if (win->x < 0 || win->x + win->actual->width > setup->width ||
      win->y + win->actual->height > setup->height)
    return (1);
  i = -1;
  while (win->actual->shape[++i])
    {
      if (win->actual->shape[i] == '*' &&
	  win->screen[win->y + i / win->actual->width]
	  [win->x + i % win->actual->width].pix == '*')
	return (1);
    }
  return (0);
}

void	move_actual(t_screen *win, t_setup *setup, char key)
{
  if (key == 'r')
    {
      win->x++;
      if (my_move(win, setup))
	win->x--;
    }
  else if (key == 'l')
    {
      win->x--;
      if (my_move(win, setup))
	win->x++;
    }
}

void	my_drop(t_screen *win, t_setup *setup)
{
  int	k;

  k = 0;
  while (!my_move(win, setup))
    {
      win->y++;
      k++;
    }
  setup->score += k * 100;
  win->y--;
}

void	aff_game(t_screen *win, t_setup *setup)
{
  int	color;
  int	i;
  int	j;

  i = -1;
  while (++i < setup->height)
    {
      j = -1;
      while (++j < setup->width)
	{
	  color = (win->screen[i][j].color < 8 && win->screen[i][j].color > 0)
	      ? win->screen[i][j].color : 0;
	  if (win->screen[i][j].pix == '*')
	    {
	      wattron(win->game, COLOR_PAIR(color));
	      mvwprintw(win->game, i + 1, j * 2 + 1, "  ");
	      wattroff(win->game, COLOR_PAIR(color));
	    }
	}
    }
}

void	aff_tetrimino(t_screen *win, t_setup *setup)
{
  int	i;
  int	color;

  i = -1;
  win->y++;
  if (my_move(win, setup))
    {
      setup->new_tet = 0;
      my_blit(win);
      if (check_all_line(win, setup))
	setup->score += 100;
    }
  color = (win->actual->color < 8 && win->actual->color > 0)
      ? win->actual->color : 0;
  while (win->actual->shape[++i])
    if (win->actual->shape[i] == '*')
	{
	  wattron(win->game, COLOR_PAIR(color));
	  mvwprintw(win->game, win->y + i / win->actual->width,
		    (win->x + i % win->actual->width) * 2 + 1, "  ");
	  wattroff(win->game, COLOR_PAIR(color));
	}
}
