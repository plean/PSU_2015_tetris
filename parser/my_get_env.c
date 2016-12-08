/*
** my_get_env.c for get env in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 21:55:42 2016 David Zeng
** Last update Tue Mar  8 18:57:06 2016 David Zeng
*/

#include "my_fonction.h"

char	*my_get_env(char **env, char *elem)
{
  int	i;

  i = 0;
  while (env[i] != 0)
    {
      if (my_strncmp(env[i], elem, my_strlen(elem) - 1) == 0 &&
	  env[i][my_strlen(elem)] == '=')
	return (&env[i][my_strlen(elem) + 1]);
      i = i + 1;
    }
  return (NULL);
}
