/*
** my_put_nbr.c for ex7 in /home/zeng_d/test/Piscine_C_J03
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Sep 30 18:47:30 2015 David Zeng
** Last update Mon Mar 14 23:18:15 2016 Jean PLANCHER
*/

#include <unistd.h>
#include "my.h"

int		my_put_nbr(int nb)
{
  long int	nbr;

  nbr = (long int)nb;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = 0 - nbr;
    }
  if (nbr > 9)
    {
      my_put_nbr(nbr / 10);
    }
  my_putchar('0' + (nbr % 10));
  return (0);
}

void	my_putnbr_base(char *str, int nb, int n)
{
  (nb / my_strlen(str) == 0) ? (1) :
      my_putnbr_base(str, nb / my_strlen(str), n);
  (nb < 0) ? write(n, "-", 1) : write(n, &str[nb % my_strlen(str)], 1);
}
