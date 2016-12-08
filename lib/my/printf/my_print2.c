/*
** test1.c for test in /home/zeng_d/test/tmp
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Nov  8 23:03:26 2015 David Zeng
** Last update Mon Dec 14 18:22:18 2015 David Zeng
*/

#include <stdarg.h>
#include "my.h"

void		my_put_nbr_base(unsigned int nb, char *base)
{
  unsigned int	tmp;
  int		base_size;

  base_size = my_strlen(base);
  tmp = nb % base_size;
  if (nb / base_size > 0)
    my_put_nbr_base(nb / base_size, base);
  my_putchar(base[tmp]);
}

int		my_printx(va_list list, int *n)
{
  unsigned int	nb;

  nb = va_arg(list, unsigned int);
  my_put_nbr_base(nb, "0123456789abcdef\0");
  if (nb == 0)
    *n = *n + 1;
  while (nb > 0)
    {
      nb = nb / 16;
      *n = *n + 1;
    }
  return (0);
}

int		my_printX(va_list list, int *n)
{
  unsigned int	nb;

  nb = va_arg(list, unsigned int);
  my_put_nbr_base(nb, "0123456789ABCDEF\0");
  if (nb == 0)
    *n = *n + 1;
  while (nb > 0)
    {
      nb = nb / 16;
      *n = *n + 1;
    }
  return (0);
}

int		my_printo(va_list list, int *n)
{
  unsigned int	nb;

  nb = va_arg(list, unsigned int);
  my_put_nbr_base(nb, "01234567\0");
  if (nb == 0)
    *n = *n + 1;
  while (nb > 0)
    {
      nb = nb / 8;
      *n = *n + 1;
    }
  return (0);
}

int	my_printper(va_list list, int *n)
{
  if (list)
    my_putchar('%');
  *n = *n + 1;
  return (0);
}
