/*
** test1.c for test in /home/zeng_d/test/tmp
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Nov  8 23:03:26 2015 David Zeng
** Last update Wed Feb 17 21:41:19 2016 David Zeng
*/

#include <stdarg.h>
#include "my.h"

void		my_sput_nbr_base(char *buffer, unsigned int nb, char *base)
{
  unsigned int	tmp;
  int		base_size;

  base_size = my_strlen(base);
  tmp = nb % base_size;
  if (nb / base_size > 0)
    my_sput_nbr_base(&buffer[1], nb / base_size, base);
  my_sputchar(buffer, base[tmp]);
}

int		my_sprintx(va_list list, char *buffer)
{
  unsigned int	nb;
  int		n;

  n = 0;
  nb = va_arg(list, unsigned int);
  my_sput_nbr_base(buffer, nb, "0123456789abcdef");
  while (nb > 0)
    {
      nb = nb / 16;
      n = n + 1;
    }
  buffer[n] = 0;
  my_revstr(buffer);
  return (n);
}

int		my_sprintX(va_list list, char *buffer)
{
  unsigned int	nb;
  int		n;

  nb = va_arg(list, unsigned int);
  n = 0;
  my_sput_nbr_base(buffer, nb, "0123456789ABCDEF");
  while (nb > 0)
    {
      nb = nb / 16;
      n = n + 1;
    }
  buffer[n] = 0;
  my_revstr(buffer);
  return (n);
}

int		my_sprinto(va_list list, char *buffer)
{
  unsigned int	nb;
  int		n;

  n = 0;
  nb = va_arg(list, unsigned int);
  my_sput_nbr_base(buffer, nb, "01234567");
  while (nb > 0)
    {
      nb = nb / 8;
      n = n + 1;
    }
  buffer[n] = 0;
  my_revstr(buffer);
  return (n);
}

int	my_sprintper(va_list list, char *buffer)
{
  (void)list;
  my_sputchar(buffer, '%');
  return (1);
}
