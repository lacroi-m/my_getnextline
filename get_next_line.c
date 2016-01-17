/*
** get_next_line.c for get_next_line in /home/lacroi_m/CPE/CPE_2015_getnextline
** 
** Made by zemax DUC
** Login   <lacroi_m@epitech.net>
** 
** Started on  Sun Jan 17 17:58:27 2016 zemax DUC
** Last update Sun Jan 17 19:30:32 2016 zemax DUC
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int          my_strlen(char *str)
{
  int        i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}

char    *my_strnmcat(char *dest,char *src, int n)
{
  char  *line;
  int   dlen;
  int   i;

  i = 0;
  dlen = my_strlen(dest);
  if ((line = malloc(dlen + n + 1)) == NULL)
    return (NULL);
  while (i < dlen + n)
    {
      if (i < dlen)
        line[i] = dest[i];
      else
        line[i] = src[i - dlen];
      ++i;
    }
  line[dlen + n] = '\0';
  free(dest);
  return (line);
}

char    *my_strndup(char *src, int n)
{
  char  *cpy;
  int   i;

  if (src == NULL || (cpy = malloc(n + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i < n)
    {
      cpy[i] = src[i];
      ++i;
    }
  cpy[i] = '\0';
  return (cpy);
}

char            *save_check(char **cache)
{
  char          *line;
  char          *tmp;
  int           i;

  i = 0;
  if (*cache != NULL)
    {
      while (cache[i] != '\0')
	{
	  if (*cache[i] == '\n')
	    {
	      tmp = *cache;
	      line = my_strndup(*cache, i);
	      *cache = my_strndup(*cache + i + 1, my_strlen(*cache + i + 1));
	      free(tmp);
	      return (line);
	    }
	  ++i;
	}
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*cache;
  char		*line;
  char		buffer[READ_SIZE + 1];
  int		i;
  int		read_size;

  if ((line = save_check(&cache)) != NULL)
    {
      return (line);
    }
  while ((read_size = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[read_size] = '\0';
      i = 0;
      while (i < read_size)
        {
          if (buffer[i] == '\n' || buffer[i] == '\0')
            {
              line = my_strnmcat(cache, buffer, i);
	      cache = my_strndup(buffer + i + 1, my_strlen(buffer + i + 1));
              return (line);
            }
          ++i;
        }
      cache = my_strnmcat(cache, buffer, my_strlen(buffer));
    }
}
