/*
** my_void_file.c for my_void_file in /home/zeng_d/rendu/Unix/PSU_2015_tetris/screen
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar 18 15:46:14 2016 David Zeng
** Last update Fri Mar 18 15:49:00 2016 David Zeng
*/

#include "my_fonction.h"

int		my_void_file(char *str, t_mino *mino)
{
  if (str == NULL)
    {
      mino->error = 1;
      return (0);
    }
  return (-1);
}
