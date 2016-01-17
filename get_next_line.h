/*
** get_next_line.h for  in /home/lacroi_m/CPE/CPE_2015_getnex
tline
** 
** Made by zemax DUC
** Login   <lacroi_m@epitech.net>
** 
** Started on  Tue Jan 12 14:19:52 2016 zemax DUC
** Last update Sun Jan 17 19:30:07 2016 zemax DUC
*/
#ifndef GET_NEXT_LINE_H_

# define GET_NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>

# ifndef READ_SIZE
#  define READ_SIZE (2)
# endif /*READ_SIZE*/

char	*save_check(char **cache);
char	*get_next_line(const int fd);

#endif /*GET_NEXT_LINE_H_*/
