/*
** my_get_dbl.c for double in /home/zeng_d/rendu/Info/gfx_wolf3d/data
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Dec 19 13:53:25 2015 David Zeng
** Last update Mon Feb 22 21:28:21 2016 David Zeng
*/

#include "my.h"

double		my_dec_pow(int nb)
{
  double	i;

  i = 1;
  while (nb > 0)
    {
      nb = nb / 10;
      i = i * 10;
    }
  return (i);
}

double		my_get_dbl(char *str)
{
  int		i;
  double	pow;
  double	nb;
  int		tmp;

  nb = my_getnbr(str);
  tmp = (int)nb;
  i = 0;
  while (tmp > 0)
    {
      tmp = tmp / 10;
      i = i + 1;
    }
  if (str[i] == '.' && str[i + 1] != '\0')
    {
      i = i + 1;
      tmp = my_getnbr(&str[i]);
      pow = my_dec_pow(tmp);
      nb = nb + (double)tmp / pow;
    }
  return (nb);
}
