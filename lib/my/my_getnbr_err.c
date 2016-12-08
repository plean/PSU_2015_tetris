/*
** my_getnbr.c for mygetnbr in /home/zeng_d/test/tmp
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov  2 22:12:18 2015 David Zeng
** Last update Tue Mar  1 02:28:19 2016 David Zeng
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_getnbr_err(char *str)
{
  int	nb;
  int	i;
  int	flag;

  i = 0;
  nb = 0;
  flag = 0;
  if (str[i] == '-')
    {
      flag = 1;
      i = 1;
    }
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      nb = (nb + (str[i] - '0')) * 10;
      i = i + 1;
    }
  (flag == 1) ? (nb = 0 - nb) : (nb = nb);
  return (nb / 10);
}
