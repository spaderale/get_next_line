#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif


size_t  ft_len(char *str);
char    *get_next_line(int fd);
char    *ft_strchr(char *str, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *line_allocation(int fd, char *str);
char    *ft_next_line(char *str);
char    *ft_rem_line(char *line);

#endif
