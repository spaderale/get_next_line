/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:54:40 by abroslav          #+#    #+#             */
/*   Updated: 2025/06/12 19:01:12 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

size_t	ft_len(char *str);
char	*get_next_line_bonus(int fd);
char	*ft_strchr(char *s1, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*line_allocation(int fd, char *str);
char	*ft_next_line(char *str);
char	*ft_rem_line(char *line);

#endif
