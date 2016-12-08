/*
** screen.h for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:26:29 2016 Jean PLANCHER
** Last update Mon Mar 21 22:21:00 2016 Jean PLANCHER
*/

#ifndef SCREEN_H_
# define SCREEN_H_

# include "my_fonction.h"

# define BORDER_GAME '|', '|', '-', '-', '/', '\\', '\\', '/'
# define GHEIGHT (setup->height + 2)
# define GWIDTH ((setup->width << 1) + 2)
# define SHEIGHT 11
# define SWIDTH 25
# define NHEIGHT ((tetrimino->max_h > 2) ? tetrimino->max_h : 2)
# define NWIDTH ((tetrimino->max_w * 2 > 6) ? tetrimino->max_w << 1 : 6)
# define STARTX ((COLS - setup->width) >> 1)
# define STARTY ((LINES - setup->height) >> 1)

typedef struct	s_pix
{
  char		pix;
  int		color;
}		t_pix;

typedef struct	s_screen
{
  WINDOW	*game;
  WINDOW	*next;
  WINDOW	*score;
  t_pix		**screen;
  t_mino	*actual;
  int		x;
  int		y;
  int		is_ended;
}		t_screen;

int	init_score(t_setup *setup, t_screen *win);
void	write_hs(int score);
void	aff_next(t_screen *win, t_setup *setup, t_list *tetriminos);
void	aff_game(t_screen *win, t_setup *setup);
void	my_pause(t_setup *setup);
int	my_init_color(void);
void	aff_tetrimino(t_screen *win, t_setup *setup);
void	move_actual(t_screen *win, t_setup *setup, char key);
void	my_erase(t_setup *setup);
void	my_blit(t_screen *win);
int	check_all_line(t_screen *win, t_setup *setup);
void	my_drop(t_screen *win, t_setup *setup);
t_mino	*rotate_tetrimino_l(t_mino *actual);
t_mino	*rotate_tetrimino_r(t_mino *actual);
int	my_move(t_screen *win, t_setup *setup);
void	my_end(int i);

#endif /* !SCREEN_H_ */
