/*
** my_sput_nbr.c for sprintf in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Feb 17 03:46:24 2016 David Zeng
** Last update Wed Feb 17 15:33:20 2016 David Zeng
*/

#include "my.h"
#include <unistd.h>

void		my_sput_nbr(char *buffer, int nb)
{
  long int	nbr;
  int		i;

  nbr = (long int)nb;
  i = 0;
  if (nbr < 0)
    {
      my_sputchar(buffer, '-');
      i = 1;
      nbr = 0 - nbr;
    }
  if (nbr > 9)
    {
      my_sput_nbr(&buffer[1 + i], nbr / 10);
    }
  my_sputchar(&buffer[i], '0' + (nbr % 10));
}
