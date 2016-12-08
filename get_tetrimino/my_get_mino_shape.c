/*
** my_get_mino_shape.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Mar  2 00:30:27 2016 David Zeng
** Last update Wed Mar 16 02:31:54 2016 David Zeng
*/

#include "my_fonction.h"

int		my_get_mino_shape(t_mino *mino, char *str)
{
  int		i;
  int		j;

  if (mino->error == 1)
    return (0);
  if (mino->shape == NULL)
    {
      if ((mino->shape = malloc(mino->width * mino->height + 1)) == NULL)
	return (1);
      mino->shape[0] = 0;
    }
  i = 0;
  j = my_strlen(str);
  if (my_strlen(mino->shape) + mino->width > mino->width * mino->height)
    return (0);
  my_strcat(mino->shape, str);
  while (j + i < mino->width)
    {
      my_strcat(mino->shape, " ");
      i = i + 1;
    }
  return (0);
}
