/*
** my_get_param.c for tetris in /home/zeng_d/rendu/Unix/PSU_2015_tetris
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Mar  2 21:58:28 2016 David Zeng
** Last update Wed Mar 16 02:17:21 2016 David Zeng
*/

#include "my_fonction.h"

char		*my_get_long_param(int argc, char **argv, char *ref)
{
  int		i;
  int		ref_len;

  i = 0;
  if (argv == NULL || ref == NULL)
    return (NULL);
  ref_len = my_strlen(ref);
  while (i < argc)
    {
      if (my_strncmp(argv[i], ref, ref_len) == 0)
	return (my_strdup(&argv[i][ref_len]));
      i = i + 1;
    }
  return (NULL);
}

char		*my_get_param(int argc, char **argv, char *ref)
{
  int		i;

  i = 0;
  if (argv == NULL || ref == NULL)
    return (NULL);
  while (i < argc)
    {
      if (my_strcmp(argv[i], ref) == 0)
	{
	  if (argv[i + 1] != NULL)
	    return (my_strdup(argv[i + 1]));
	  else
	    {
	      my_aff_help(argv[0]);
	      exit(1);
	    }
	}
      i = i + 1;
    }
  return (NULL);
}
