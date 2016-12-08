/*
** disp_stdarg.c for disp in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Nov  5 11:58:05 2015 David Zeng
** Last update Wed Feb 10 16:04:44 2016 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char	*my_do_str(char *str)
{
  str[0] = 'c';
  str[1] = 's';
  str[2] = 'i';
  str[3] = 'd';
  str[4] = 'u';
  str[5] = 'o';
  str[6] = 'x';
  str[7] = 'X';
  str[8] = 't';
  str[9] = 'b';
  str[10] = 'S';
  str[11] = 'p';
  str[12] = 'C';
  str[13] = '\0';
  return (str);
}

int	my_printtab(va_list list, int *n)
{
  char	**str;

  (void)n;
  str = va_arg(list, char **);
  my_show_tab(str);
  return (0);
}

void	do_per(char c, va_list list, int *n, int i)
{
  t_cas	cas[13];
  char	str[14];

  my_do_str(str);
  cas[0] = &my_printc;
  cas[1] = &my_prints;
  cas[2] = &my_printi;
  cas[3] = &my_printi;
  cas[4] = &my_printu;
  cas[5] = &my_printo;
  cas[6] = &my_printx;
  cas[7] = &my_printX;
  cas[8] = &my_printtab;
  cas[9] = &my_printb;
  cas[10] = &my_printS;
  cas[11] = &my_printp;
  cas[12] = &my_printc;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	cas[i](list, n);
      i = i + 1;
    }
}

int	disp_stdarg(const char *str, int *i,  va_list list, int *n)
{
  int	j;
  char	string[14];

  j = 0;
  my_do_str(string);
  while (string[j] != str[*i] && string[j] != '\0')
    j = j + 1;
  if (str[*i] == '\0' || string[j] == '\0')
    {
      my_putchar('%');
      *n = *n + 1;
      return (0);
    }
  do_per((char)str[*i], list, n, 0);
  *i = *i + 1;
  return (0);
}
