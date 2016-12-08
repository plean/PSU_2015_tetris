/*
** my_blit.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Mar 18 16:15:01 2016 Jean PLANCHER
** Last update Tue Mar 22 14:00:55 2016 Jean PLANCHER
*/

#include "screen.h"

static int	my_check_line(t_pix *line)
{
  int		i;

  i = -1;
  while (line[++i].pix)
    {
      if (line[i].pix == ' ')
	return (1);
    }
  return (0);
}

int	check_all_line(t_screen *win, t_setup *setup)
{
  int	i;
  int	e;

  i = -1;
  e = 0;
  while (win->screen[++i])
    if (!my_check_line(win->screen[i]))
	{
	  while (--i >= 0)
	    win->screen[i + 1] = win->screen[i];
	  while (++i < setup->width)
	    win->screen[0][i].pix = ' ';
	  e = 1;
	  setup->line++;
	  if (setup->line == 10)
	    {
	      setup->line = 0;
	      setup->level += (setup->level < 10);
	    }
	}
  return (e);
}

void	my_blit(t_screen *win)
{
  int	i;

  i = -1;
  win->y--;
  while (win->actual->shape[++i])
    if (win->actual->shape[i] == '*')
	{
	  win->screen[win->y + i / win->actual->width]
	  [win->x + i % win->actual->width].pix = '*';
	  win->screen[win->y + i / win->actual->width]
	  [win->x + i % win->actual->width].color = win->actual->color;
	}
  win->y++;
}
