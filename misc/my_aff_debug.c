/*
** my_aff_debug.c for tetris in /home/zeng_d/.emacs.d/private/tabbar
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar  4 18:27:53 2016 David Zeng
** Last update Sun Mar 13 22:13:09 2016 David Zeng
*/

#include "my_fonction.h"

char		*ch_str(char *str, char *tmp)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (my_strcmp(str, " ") == 0)
    my_strcpy(tmp, "(space)");
  else
    {
      while (str[i] != 0)
	{
	  if (str[i] == 27)
	    {
	      tmp[j] = '^';
	      tmp[++j] = 'E';
	    }
	  else
	    tmp[j] = str[i];
	  j = j + 1;
	  i = i + 1;
	}
      tmp[j] = 0;
    }
  return (tmp);
}

void		my_aff_keys(t_setup *setup)
{
  char		tmp[100];

  my_printf("Key Left : %s\n", ch_str(setup->left, tmp));
  my_printf("Key Right : %s\n", ch_str(setup->right, tmp));
  my_printf("Key Turn : %s\n", ch_str(setup->turn, tmp));
  my_printf("Key Drop : %s\n", ch_str(setup->drop, tmp));
  my_printf("Key Quit : %s\n", ch_str(setup->quit, tmp));
  my_printf("Key Pause : %s\n", ch_str(setup->pause, tmp));
}

void		my_aff_debug(t_setup *setup, t_list *tetrimino)
{
  my_printf("*** DEBUG MODE ***\n");
  my_aff_keys(setup);
  my_printf("Next : ");
  if (setup->next == true)
    my_printf("Yes\n");
  else
    my_printf("No\n");
  my_printf("Level : %d\nSize : %d*%d\n", setup->level,
	    setup->height, setup->width);
  my_aff_tetrimino(tetrimino);
  my_printf("Press a key to start Tetris\n");
  read(0, NULL, 1);
}
