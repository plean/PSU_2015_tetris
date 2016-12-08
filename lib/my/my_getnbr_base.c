/*
** my_getnbr_base.c for getnbr_base in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Feb 17 23:06:44 2016 David Zeng
** Last update Wed Feb 17 23:42:42 2016 David Zeng
*/

#include "my.h"

int		my_check_nb_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] != 0)
    {
      if (c == base[i])
	return (i);
      i = i + 1;
    }
  return (-1);
}

unsigned int	my_getnbr_base(char *str, char *base)
{
  int	nb;
  int	i;
  int	tmp;

  nb = 0;
  i = 0;
  if (my_strncmp(str, "0x", 2) == 0 &&
      my_strcmp(base, "0123456789abcdef") == 0)
    i = 2;
  while (str[i] != 0)
    {
      if ((tmp = my_check_nb_base(str[i], base)) == -1)
	return (-1);
      nb = (nb + tmp) * my_strlen(base);
      i = i + 1;
    }
  nb = nb / my_strlen(base);
  return (nb);
}
