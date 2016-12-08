/*
** my_print3.c for print 3 in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov  9 00:19:45 2015 David Zeng
** Last update Sun Dec 27 17:06:18 2015 David Zeng
*/

#include <stdarg.h>
#include "my.h"

void			my_putunsigned(unsigned int nb)
{
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar('0' + (nb % 10));
}

int			my_printu(va_list list, int *n)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  my_putunsigned(nb);
  if (nb == 0)
    *n = *n + 1;
  while (nb > 0)
    {
      nb = nb / 10;
      *n = *n + 1;
    }
  return (0);
}

int			my_printb(va_list list, int *n)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  my_put_nbr_base(nb, "01");
  if (nb == 0)
    *n = *n + 1;
  while (nb > 0)
    {
      nb = nb / 2;
      *n = *n + 1;
    }
  return (0);
}

void			my_put_16(unsigned long int nb, char *base)
{
  unsigned long int	tmp;
  unsigned long int	base_size;

  base_size = my_strlen(base);
  tmp = nb % base_size;
  if (nb / base_size > 0)
    my_put_16(nb / base_size, base);
  my_putchar(base[tmp]);
}

int			my_printp(va_list list, int *n)
{
  unsigned long int	nb;

  nb = va_arg(list, unsigned long int);
  if (nb == 0)
    {
      my_putstr("(nil)");
      *n = *n + 5;
      return (0);
    }
  my_putstr("0x");
  *n = *n + 2;
  my_put_16(nb, "0123456789abcdef\0");
  while (nb > 0)
    {
      nb = nb / 16;
      *n = *n + 1;
    }
  return (0);
}
