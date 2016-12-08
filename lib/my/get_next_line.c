/*
** my_get_next_line.c for get next line in /home/zeng_d/test/Get_next_line
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Dec  4 13:06:27 2015 David Zeng
** Last update Wed Feb  3 22:33:13 2016 David Zeng
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char		*my_realloc(char *pointer, unsigned int size)
{
  char		*str;

  if (pointer != NULL)
    {
      str = malloc(sizeof(char) * (my_strlen(pointer) + size + 1));
      if (str == NULL)
	return (NULL);
      my_strncpy(str, pointer, my_strlen(pointer));
      free(pointer);
    }
  else
    {
      if ((str = malloc(size)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

void		my_replace_flag(int *flag, int *ind, char *buffer)
{
  if (buffer[*ind] == 0)
    *ind = 0;
  else
    {
      *flag = 1;
      *ind = *ind + 1;
      if (buffer[*ind] == 0)
	*ind = 0;
    }
}

char		*get_next_line(const int fd)
{
  static int	ind;
  int		debut;
  int		flag;
  char		*str;
  int		ret;
  static char	buffer[READ_SIZE];

  flag = 0;
  str = NULL;
  while (flag != 1)
    {
      if (ind == 0)
	{
	  if ((ret = read((int)fd, buffer, READ_SIZE)) == 0 || ret == -1)
	    return (str);
	  buffer[ret] = 0;
	}
      debut = ind--;
      while (buffer[++ind] != '\n' && buffer[ind] != 0);
      if ((str = my_realloc(str, sizeof(char) * (ind - debut + 1))) == NULL)
	return (NULL);
      my_strncpy(&str[my_strlen(str)], &buffer[debut], ind - debut);
      my_replace_flag(&flag, &ind, buffer);
    }
  return (str);
}
