/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:36:59 by abroslav          #+#    #+#             */
/*   Updated: 2025/06/17 19:07:21 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line_bonus(int fd)
{
	char			*out;
	static char		*str[FD_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	str[fd] = line_allocation(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	out = ft_next_line(str[fd]);
	str[fd] = ft_rem_line(str[fd]);
	return (out);
}

#include <stdio.h>

int	main(void)
{
	char	*s;
	int		fd;
	int		i;

	//primeiro file
	fd = open("teste1.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	s = get_next_line_bonus(fd);
	while (s != NULL)
	{
		printf("teste1.txt linha %d: %s", i, s);
		free(s);
		i++;s = get_next_line_bonus(fd);
	}
	close(fd);

	//segundo file
	fd = open("teste2.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	s = get_next_line_bonus(fd);
	while (s != NULL)
	{
		printf("teste2.txt linha %d: %s", i, s);
		free(s);
		i++;
		s = get_next_line_bonus(fd);
	}
	close(fd);

	//terceiro file
	fd = open("teste3.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	s = get_next_line_bonus(fd);
	while (s != NULL)
	{
		printf("teste3.txt linha %d: %s", i, s);
		free(s);
		i++;
		s = get_next_line_bonus(fd);
	}
	close(fd);
	return (0);
}
