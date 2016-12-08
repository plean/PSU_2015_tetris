/*
** my_putchar.c for myputchar in /home/zeng_d/rendu/Piscine_C_J07/lib/my
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Oct  7 22:55:29 2015 David Zeng
** Last update Fri Feb  5 02:15:27 2016 David Zeng
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
