/*
** my_aff_help.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 22:19:24 2016 David Zeng
** Last update Wed Mar 16 01:33:09 2016 David Zeng
*/

#include "my_fonction.h"

int		my_aff_help(char *str)
{
  my_printf("Usage: %s [options]\n", str);
  my_printf("Options:\n");
  my_printf("  --help\t\t Display this help\n");
  my_printf("  -l --level={num}\t Start Tetris at level num\n");
  my_printf("  -kl --key-left={K}\t Move tetrimino on LEFT with key K\n");
  my_printf("  -kr --key-right={K}\t Move tetrimino on RIGHT with key K\n");
  my_printf("  -kt --key-turn={K}\t Turn tetrimino with key K\n");
  my_printf("  -kd --key-drop={K}\t Set default DROP on key K\n");
  my_printf("  -kq --key-quit={K}\t Quit program when press key K\n");
  my_printf("  -kp --key-pause={K}\t Pause and restart game when press key K\n");
  my_printf("  --map-size={row,col}\t Set game size at row, col\n");
  my_printf("  -w --without-next\t Hide next tetrimino\n");
  my_printf("  -d --debug\t\t Debug mode\n");
  return (1);
}
