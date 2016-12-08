/*
** my_parse_error.c for my_parse_error in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Mar 16 00:42:13 2016 David Zeng
** Last update Thu Mar 17 15:24:41 2016 
*/

#include "my_fonction.h"

int		my_check_arg(char **argv, char *ref, char *ref2, int *i)
{
  if (ref != NULL && my_strcmp(argv[*i], ref) == 0)
    {
      *i = *i + 1;
      return (1);
    }
  else if (my_strncmp(argv[*i], ref2, my_strlen(ref2)) == 0)
    return (1);
  return (0);
}

int		my_check_rest(char **argv, int *i)
{
  if (my_strcmp(argv[*i], "-w") == 0 ||
      my_strcmp(argv[*i], "--without-next") == 0 ||
      my_strcmp(argv[*i], "-d") == 0 ||
      my_strcmp(argv[*i], "--debug") == 0)
    return (1);
  return (0);
}

int		my_parse_error(int argc, char **argv, t_setup *new)
{
  int		i;

  i = 1;
  while (i < argc)
    {
      if (my_check_arg(argv, "-kl", "--key-left=", &i) == 1 ||
	  my_check_arg(argv, "-kr", "--key-right=", &i) == 1 ||
	  my_check_arg(argv, "-kt", "--key-turn=", &i) == 1 ||
	  my_check_arg(argv, "-kd", "--key-drop=", &i) == 1 ||
	  my_check_arg(argv, "-kq", "--key-quit=", &i) == 1 ||
	  my_check_arg(argv, "-kp", "--key-pause=", &i) == 1 ||
	  my_check_arg(argv, "-l", "--level=", &i) == 1 ||
	  my_check_arg(argv, NULL, "--map-size=", &i) == 1 ||
	  my_check_rest(argv, &i) == 1)
	{
	  i = i + 1;
	}
      else
	{
	  free(new);
	  return (my_aff_help(argv[0]));
	}
    }
  return (0);
}
