/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:33:44 by abroslav          #+#    #+#             */
/*   Updated: 2025/06/04 20:02:22 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//para encontrar char c. Essa funcao retorna um ponteiro para a primeira
//ocorrencia de c em uma string ou nulo se o char nao for encontrado

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_len(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

//Combina duas strings e retorna uma string contendo a combinação de ambas

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*out;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	out = (char *)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!out)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
		out[j++] = s1[i++];
	i = 0;
	while (s2[i])
		out[j++] = s2[i++];
	out[j] = '\0';
	free(s1);
	return (out);
}

//Essa funcao le uma linha de texto do fd e retorna a linha lida
//ssize_t signed size
//read(int fd, void *bufeer, size_t counter) retorna ssize_t do byte lido do fd
//-1 para erro ou o numero do byte, counter é o tamanho max de bytes lido

char	*line_allocation(int fd, char *str)
{
	char		*buffer;
	ssize_t		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (!(ft_strchr(str, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		printf("BUFFER_SIZE=%d | Lidos: %s\n", BUFFER_SIZE, buffer);
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

//extrai a proxima linha de uma str e retorna nova string contendo a prox. linha

char	*ft_next_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

//remove a proxima linha de uma str e retorna nova str

char	*ft_rem_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	str = malloc(ft_len(line) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
	{
		str[j++] = line[i++];
	}
	str[j] = '\0';
	free(line);
	return (str);
}
