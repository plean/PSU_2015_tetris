/*
** my_print3.c for print 3 in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov  9 00:19:45 2015 David Zeng
** Last update Wed Feb 17 21:43:31 2016 David Zeng
*/

#include <stdarg.h>
#include "my.h"

void			my_sputunsigned(char *buffer, unsigned int nb)
{
  if (nb > 9)
    my_sput_nbr(&buffer[1], nb / 10);
  my_sputchar(buffer, '0' + (nb % 10));
}

int			my_sprintu(va_list list, char *buffer)
{
  unsigned int		nb;
  int			n;

  nb = va_arg(list, unsigned int);
  my_sputunsigned(buffer, nb);
  n = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      n = n + 1;
    }
  buffer[n] = 0;
  my_revstr(buffer);
  return (n);
}

int			my_sprintb(va_list list, char *buffer)
{
  unsigned int		nb;
  int			n;

  nb = va_arg(list, unsigned int);
  my_sput_nbr_base(buffer, nb, "01");
  n = 0;
  while (nb > 0)
    {
      nb = nb / 2;
      n = n + 1;
    }
  buffer[n] = 0;
  my_revstr(buffer);
  return (n);
}

void			my_sput_16(char *buffer,
				  unsigned long int nb, char *base)
{
  unsigned long int	tmp;
  unsigned long int	base_size;

  base_size = my_strlen(base);
  tmp = nb % base_size;
  if (nb / base_size > 0)
    my_sput_16(&buffer[1], nb / base_size, base);
  my_sputchar(buffer, base[tmp]);
}

int			my_sprintp(va_list list, char *buffer)
{
  unsigned long int	nb;
  int			n;

  nb = va_arg(list, unsigned long int);
  my_sputstr(buffer, "0x");
  my_sput_16(&buffer[my_strlen("0x")], nb, "0123456789abcdef\0");
  n = 2;
  while (nb > 0)
    {
      nb = nb / 16;
      n = n + 1;
    }
  buffer[n] = 0;
  my_revstr(buffer);
  return (n);
}
