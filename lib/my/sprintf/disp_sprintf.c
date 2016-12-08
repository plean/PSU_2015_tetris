/*
** disp_stdarg.c for disp in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Nov  5 11:58:05 2015 David Zeng
** Last update Wed Feb 17 15:33:42 2016 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char	*my_sdo_str(char *str)
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

int	my_sprinttab(va_list list, char *buffer)
{
  char	**str;
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  str = va_arg(list, char **);
  my_sshow_tab(buffer, str);
  while (str[i] != NULL)
    {
      nb += my_strlen(str[i]) + 1;
      i = i + 1;
    }
  return (nb);
}

int		do_sper(char c, va_list list, char *buffer)
{
  t_cass	cas[13];
  char		str[14];
  int		i;

  my_sdo_str(str);
  i = -1;
  cas[0] = &my_sprintc;
  cas[1] = &my_sprints;
  cas[2] = &my_sprinti;
  cas[3] = &my_sprinti;
  cas[4] = &my_sprintu;
  cas[5] = &my_sprinto;
  cas[6] = &my_sprintx;
  cas[7] = &my_sprintX;
  cas[8] = &my_sprinttab;
  cas[9] = &my_sprintb;
  cas[10] = &my_sprintS;
  cas[11] = &my_sprintp;
  cas[12] = &my_sprintc;
  while (str[++i] != '\0')
    {
      if (str[i] == c)
	return (cas[i](list, buffer));
    }
  return (0);
}

int	disp_sprintf(const char *str, int *i, va_list list, char *buffer)
{
  int	j;
  char	string[14];
  int	nb;

  j = 0;
  my_sdo_str(string);
  while (string[j] != str[*i] && string[j] != '\0')
    j = j + 1;
  if (str[*i] == '\0' || string[j] == '\0')
    {
      my_sputchar(buffer, '%');
      return (1);
    }
  nb = do_sper((char)str[*i], list, buffer);
  *i = *i + 1;
  return (nb);
}
