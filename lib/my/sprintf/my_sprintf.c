/*
** my_printf.c for my_printf in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Nov  8 21:43:31 2015 David Zeng
** Last update Wed Feb 17 15:22:18 2016 David Zeng
*/

#include <stdarg.h>
#include "my.h"

void		my_fill_sbuffer(char *out, char *buffer, int nb)
{
  buffer[nb] = 0;
  my_strcpy(out, buffer);
}

int		my_sprintf(char *out, const char *format, ...)
{
  int		i;
  int		nb;
  va_list	list;
  char		buffer[SPRINTF_SIZE];

  i = 0;
  nb = 0;
  va_start(list, format);
  while (format[i] != '\0')
    {
      while (format[i] != '%' && format[i] != '\0')
	{
	  my_sputchar(&buffer[nb], format[i]);
	  i = i + 1;
	  nb = nb + 1;
	}
      if (format[i] == '%')
	{
	  i = i + 1;
	  nb = nb + disp_sprintf(format, &i, list, &buffer[nb]);
	}
    }
  my_fill_sbuffer(out, buffer, nb);
  va_end(list);
  return (0);
}
