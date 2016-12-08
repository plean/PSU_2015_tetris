/*
** init_score.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Mar 14 18:55:31 2016 Jean PLANCHER
** Last update Mon Mar 21 22:17:35 2016 Jean PLANCHER
*/

#include "screen.h"

static void	init_screen(t_setup *setup, t_screen *win)
{
  int	x;
  int	y;

  setup->wline = LINES;
  setup->wcol = COLS;
  if ((win->screen = malloc(sizeof(t_pix *) * (setup->height + 2))) == NULL)
    return ;
  y = -1;
  while (++y < setup->height + 2)
    {
      if ((win->screen[y] = malloc(sizeof(t_pix) * setup->width)) == NULL)
	return ;
      x = -1;
      while (++x < setup->width)
	win->screen[y][x].pix = ' ';
      win->screen[y][x].pix = 0;
    }
  win->screen[y] = 0;
}

int	init_score(t_setup *setup, t_screen *win)
{
  int	fd;

  setup->new_tet = 0;
  setup->start_time = time(NULL);
  win->is_ended = 0;
  init_screen(setup, win);
  if ((fd = open(".high_score", O_RDONLY)) == -1)
    {
      if ((fd = open(".high_score", O_CREAT, 0644)) == -1)
	{
	  endwin();
	  return (1);
	}
      setup->high_score = 0;
      close (fd);
      return (0);
    }
  setup->high_score = my_getnbr(get_next_line(fd));
  if (setup->high_score == -1)
    setup->high_score++;
  close(fd);
  return (0);
}

int	my_init_color(void)
{
  start_color();
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
  init_pair(1, COLOR_WHITE, COLOR_RED);
  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_WHITE, COLOR_YELLOW);
  init_pair(4, COLOR_WHITE, COLOR_BLUE);
  init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(6, COLOR_WHITE, COLOR_CYAN);
  init_pair(7, COLOR_WHITE, COLOR_WHITE);
  return (0);
}

void	write_hs(int score)
{
  int	fd;

  if ((fd = open(".high_score", O_WRONLY)) == -1)
      return ;
  my_putnbr_base("0123456789", score, fd);
  close(fd);
}
