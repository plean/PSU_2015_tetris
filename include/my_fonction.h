/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Fri Mar 18 15:50:17 2016 David Zeng
*/

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <ncurses/curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "my_list.h"
# include "my.h"

# ifndef SIZE_READ
#  define SIZE_READ (100)
# endif /* !SIZE_READ */

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

/* GET TETRIMINOS */
typedef struct		s_mino
{
  int			width;
  int			height;
  int			color;
  int			error;
  char			*shape;
  char			name[256];
}			t_mino;

t_list			*my_get_tetrimino();
int			my_pos_add(t_list *list, void *data, int position);
void			my_sort_add(t_list *list, void *data);
int			my_get_mino_shape(t_mino *mino, char *str);
int			my_void_file(char *str, t_mino *mino);
/* GET TETRIMINOS END */

/* PARSING */
typedef struct		s_setup
{
  int			line;
  int			level;
  char			left[SIZE_READ];
  char			right[SIZE_READ];
  char			turn[SIZE_READ];
  char			drop[SIZE_READ];
  char			quit[SIZE_READ];
  char			pause[SIZE_READ];
  int			width;
  int			height;
  int			next;
  int			aff_next;
  int			debug;
  int			high_score;
  int			score;
  int			new_tet;
  int			wline;
  int			wcol;
  time_t		start_time;
}			t_setup;

typedef struct		s_ref
{
  char			ref1[4];
  char			ref2[16];
}			t_ref;

t_setup			*my_get_setup(int argc, char **argv, char **env);
int			my_init_term(char **env, int mode);
char			*my_get_param(int argc, char **argv, char *ref);
char			*my_get_long_param(int argc, char **argv, char *ref);
int			my_get_keyboard(int argc, char **argv, t_setup *new);
char			*my_get_env(char **env, char *elem);
void			my_mino_max_length(t_list *list);
int			my_parse_error(int argc, char **argv, t_setup *new);
/* PARSING END */

/* OTHER */
void			my_free_node_data(t_mino *mino);
int			my_aff_help(char *str);
void			my_aff_tetrimino(t_list *tetrimino);
void			my_aff_debug(t_setup *setup, t_list *tetrimino);
void			ch_read_state(int mode);
/* OTHER END */

/* SCREEN */
void	aff_screen(t_list *tetrimino, t_setup *setup);
/* SCREEN END */

#endif /* !MY_FONCTION_H_ */
