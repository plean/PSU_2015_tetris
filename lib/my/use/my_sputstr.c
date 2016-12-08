/*
** my_sputstr.c for sprintf in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Feb 17 03:26:26 2016 David Zeng
** Last update Wed Feb 17 03:27:48 2016 David Zeng
*/

#include <unistd.h>
#include "my.h"

void		my_sputstr(char *buffer, char *str)
{
  if (str == NULL)
    return;
  my_strcpy(buffer, str);
}
