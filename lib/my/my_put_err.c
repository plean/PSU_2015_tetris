/*
** my_put_err.c for put err in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 15:18:38 2016 David Zeng
** Last update Mon Jan 18 23:26:09 2016 David Zeng
*/

#include <unistd.h>
#include "my.h"

void	my_put_err(char *str)
{
  if (str == NULL)
    return;
  write(2, str, my_strlen(str));
}
