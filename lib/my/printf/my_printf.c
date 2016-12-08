/*
** my_printf.c for my_printf in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Nov  8 21:43:31 2015 David Zeng
** Last update Mon Dec 14 18:22:08 2015 David Zeng
*/

#include <stdarg.h>
#include "my.h"

int		my_printf(const char *format, ...)
{
  int		i;
  int		n;
  va_list	list;

  i = 0;
  n = 0;
  va_start(list, format);
  while (format[i] != '\0')
    {
      while (format[i] != '%' && format[i] != '\0')
	{
	  my_putchar(format[i]);
	  i = i + 1;
	  n = n + 1;
	}
      if (format[i] == '%')
	{
	  i = i + 1;
	  disp_stdarg(format, &i, list, &n);
	}
    }
  va_end(list);
  return (n);
}
