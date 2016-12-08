/*
** parsing.c for tetris in /home/zeng_d/rendu/Unix/PSU_2015_tetris
**
** Made by David Zeng
** Login   <David@epitech.net>
**
** Started on  Tue Mar  8 18:05:15 2016 David Zeng
** Last update Wed Mar 16 02:17:03 2016 David Zeng
*/

#include "my_fonction.h"

int		my_gcap(char *key, char *cap)
{
  char		*tmp;

  if ((tmp = tigetstr(cap)) == NULL)
    {
      my_printf("Your terminal doesn't support %s capacity\nExiting...\n", cap);
      return (1);
    }
  my_strcpy(key, tmp);
  return (0);
}

t_setup		*my_init_setup(char **env)
{
  t_setup	*new;

  if ((new = malloc(sizeof(t_setup))) == NULL)
    return (NULL);
  if (my_init_term(env, 0) == 1 || my_gcap(new->right, "kcuf1") == 1 ||
      my_gcap(new->turn, "kcuu1") == 1 || my_gcap(new->drop, "kcud1") == 1 ||
      my_gcap(new->left, "kcub1") == 1)
    {
      free(new);
      return (NULL);
    }
  new->level = 1;
  my_strcpy(new->quit, "q");
  my_strcpy(new->pause, " ");
  new->width = 10;
  new->height = 20;
  new->next = true;
  new->debug = false;
  return (new);
}

int		my_get_map_size(int argc, char **argv, t_setup *new)
{
  char		*tmp;
  int		i;
  int		debut;

  i = -1;
  if ((tmp = my_get_long_param(argc, argv, "--map-size=")) != NULL)
    {
      while (tmp[++i] >= '0' && tmp[i] <= '9');
      if (tmp[i] == ',')
	tmp[i] = 0;
      debut = i;
      while ((tmp[++debut] == ' ') && tmp[debut] != 0);
      if ((new->height = my_getnbr_err(tmp)) == -1 || new->height == 0)
	{
	  free(tmp);
	  return (my_aff_help(argv[0]));
	}
      if ((new->width = my_getnbr_err(&tmp[debut])) == -1 || new->width == 0)
	{
	  free(tmp);
	  return (my_aff_help(argv[0]));
	}
      free(tmp);
    }
 return (0);
}

int		my_get_other_setup(int argc, char **argv, t_setup *new)
{
  char		*tmp;

  if ((tmp = my_get_param(argc, argv, "-l")) != NULL)
    {
      if ((new->level = my_getnbr_err(tmp)) == -1 || new->level == 0)
	{
	  free(tmp);
	  return (my_aff_help(argv[0]));
	}
      free(tmp);
    }
  else if ((tmp = my_get_long_param(argc, argv, "--level=")) != NULL)
    {
      if ((new->level = my_getnbr_err(tmp)) == -1 || new->level == 0)
	{
	  free(tmp);
	  return (my_aff_help(argv[0]));
	}
      free(tmp);
    }
  my_get_keyboard(argc, argv, new);
  if (my_get_map_size(argc, argv, new) == 1)
    return (1);
  return (0);
}

t_setup		*my_get_setup(int ac, char **av, char **env)
{
  t_setup	*new;
  int		i;

  if ((new = my_init_setup(env)) == NULL)
    return (NULL);
  if (ac == 1)
    return (new);
  if (my_parse_error(ac, av, new) == 1)
    return (NULL);
  i = -1;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "--help") == 0)
	{
	  my_aff_help(av[0]);
	  free(new);
	  return (NULL);
	}
      else if (my_strcmp(av[i], "-w") == 0 ||
	       my_strcmp(av[i], "--without-next") == 0)
	new->next = false;
      else if (my_strcmp(av[i], "-d") == 0 || my_strcmp(av[i], "--debug") == 0)
	new->debug = true;
    }
  return ((my_get_other_setup(ac, av, new) == 1) ? NULL : new);
}
