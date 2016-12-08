/*
** main.c for tetris in /home/zeng_d/rendu/Unix/PSU_2015_tetris
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  8 18:03:47 2016 David Zeng
** Last update Mon Mar 21 22:21:27 2016 Jean PLANCHER
*/

#include "my_fonction.h"

void	my_end(int i)
{
  if (i == -1)
    my_printf("Error: window's too small.\n");
  if (i == -2)
    my_printf("Haha you just lost.\n");
}

void		my_free_node_data(t_mino *mino)
{
  free(mino->shape);
  free(mino);
}

void		my_remove_error_mino(t_list *tetrimino)
{
  t_node	*node;
  t_node	*tmp;

  node = tetrimino->debut;
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      if (((t_mino *)tmp->data)->error == 1)
	{
	  free(((t_mino *)tmp->data)->shape);
	  free(tmp->data);
	  my_del_node(tetrimino, tmp);
	}
    }
  my_mino_max_length(tetrimino);
}

int		main(int argc, char **argv, char **env)
{
  t_list	*tetrimino;
  t_setup	*setup;

  if ((setup = my_get_setup(argc, argv, env)) == NULL ||
      (tetrimino = my_get_tetrimino()) == NULL)
    {
      my_init_term(NULL, 1);
      return (1);
    }
  if (setup->debug == true)
    my_aff_debug(setup, tetrimino);
  my_init_term(NULL, 1);
  my_remove_error_mino(tetrimino);
  if (tetrimino->length == 0)
    {
      my_put_err("No tetriminos available.\n");
      free(setup);
      my_free_all(&tetrimino, &my_free_node_data);
      return (1);
    }
  srand(time(NULL));
  aff_screen(tetrimino, setup);
  free(setup);
  my_free_all(&tetrimino, &my_free_node_data);
  return (0);
}
