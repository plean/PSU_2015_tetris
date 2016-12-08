/*
** aff_screen.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:08:40 2016 Jean PLANCHER
** Last update Mon Mar 21 22:20:15 2016 Jean PLANCHER
*/

#include "screen.h"

static int	get_input(t_setup *setup, t_screen *win)
{
  char	touch[SIZE_READ];

  if (STARTX < 26 || STARTY < 2)
      return (-1);
  touch[read(0, touch, SIZE_READ)] = 0;
  if (!my_strcmp(touch, setup->quit) || win->is_ended)
    return (-win->is_ended * 2);
  else if (!my_strcmp(touch, setup->left))
    move_actual(win, setup, 'l');
  else if (!my_strcmp(touch, setup->right))
    move_actual(win, setup, 'r');
  else if (!my_strcmp(touch, setup->turn))
    {
      win->actual = rotate_tetrimino_r(win->actual);
      if (my_move(win, setup))
	win->actual = rotate_tetrimino_l(win->actual);
    }
  else if (!my_strcmp(touch, setup->drop))
    my_drop(win, setup);
  else if (!my_strcmp(touch, setup->pause))
    my_pause(setup);
  else if (!my_strcmp(touch, "n"))
    setup->new_tet = 0;
  return (1);
}

static WINDOW	*create_newwin(int width, int height, int startx, int starty)
{
  WINDOW	*local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0 , 0);
  wattron(local_win, COLOR_PAIR(0));
  wborder(local_win, BORDER_GAME);
  wattron(local_win, COLOR_PAIR(0));
  return (local_win);
}

static void	destroy_win(t_screen *win)
{
  delwin(win->game);
  delwin(win->next);
  delwin(win->score);
}

static void	my_refresh(t_screen *win, t_setup *setup, t_list *tetrimino)
{
  time_t	my_time;

  my_time = time(NULL) - setup->start_time;
  win->game = create_newwin(GWIDTH, GHEIGHT, STARTX, STARTY);
  win->next = create_newwin(NWIDTH + 2, NHEIGHT + 2, STARTX * 1.9, STARTY);
  win->score = create_newwin(SWIDTH, SHEIGHT, STARTX * 0.1, STARTY << 1);
  refresh();
  if (LINES != setup-> wline || COLS != setup->wcol)
    my_erase(setup);
  mvwprintw(win->next, 0, 1, "%s", "Next");
  aff_game(win, setup);
  mvprintw(LINES - 2, 0, "made with love by zeng_d & planch_j");
  aff_next(win, setup, tetrimino);
  aff_tetrimino(win, setup);
  wrefresh(win->game);
  mvwprintw(win->score, 2, 2, "High Score\t%d", setup->high_score);
  mvwprintw(win->score, 3, 2, "Score\t\t%d", setup->score);
  mvwprintw(win->score, 5, 2, "Lines\t\t%02d", setup->line);
  mvwprintw(win->score, 6, 2, "Level\t\t%02d", setup->level);
  mvwprintw(win->score, 8, 2, "Timer:\t%02d:%02d", my_time / 60, my_time % 60);
  wrefresh(win->next);
  wrefresh(win->score);
  usleep(100000 - (setup->level - 1) * 10000);
  setup->score += 1;
  destroy_win(win);
}

void		aff_screen(t_list *tetrimino, t_setup *setup)
{
  SCREEN	*screen;
  t_screen	win;
  int		i;

  setup->aff_next = rand() % tetrimino->length + 1;
  screen = newterm(NULL, stderr, stdin);
  set_term(screen);
  cbreak();
  keypad(stdscr, TRUE);
  raw();
  noecho();
  curs_set(0);
  if (init_score(setup, &win) || my_init_color())
    return ;
  ch_read_state(0);
  while ((i = get_input(setup, &win)) > 0)
    my_refresh(&win, setup, tetrimino);
  destroy_win(&win);
  if (setup->high_score < setup->score)
    write_hs(setup->score);
  ch_read_state(1);
  endwin();
  delscreen(screen);
  if (i < 0)
    my_end(i);
}
