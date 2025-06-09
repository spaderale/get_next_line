/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:18:11 by abroslav          #+#    #+#             */
/*   Updated: 2025/06/02 20:35:47 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

//le uma linha do fd e retorna uma nova string contendo a linha lida

char	*get_next_line(int fd)
{
	char			*out;
	static char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = line_allocation(fd, str);
	if (!str)
		return (NULL);
	out = ft_next_line(str);
	str = ft_rem_line(str);
	return (out);
}

int	main(void)
{
	char		*s;
	int			i;
	int			fd;

	fd = open("teste.txt", O_RDONLY);
	i = 1;
	s = get_next_line(fd);
	while (i < BUFFER_SIZE && s != NULL)
	{
		printf("Linha: %d: %s", i, s);
		free(s);
		i++;
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}
