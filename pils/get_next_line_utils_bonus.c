#include "get_next_line_bonus.h"

size_t  ft_len(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return (i);
}


//retorna ponteiro para primeira ocorrencia de c em str, ounull

char    *ft_strchr(char *str, int c)
{
    size_t  i;
	i = 0;
    if (!str)
        return (0);
    if (c == '\0') 
        return((char *)&str[ft_len(str)]);
    while (str[i])
        {
            if (str[i] == (char)c)
                return ((char *)&str[i]);
            i++;
        }
    return (0);
}

//junta s1 e s2, retorna new str, libera s1

char    *ft_strjoin(char *s1, char *s2)
{
    size_t  i, j;
    char    *out;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        if (!s1)
            return (NULL);
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

// le o fd e adciona ao buffer enquanto nao encontrar '\n' ou eof


char    *line_allocation(int fd, char *str)
{
    char        *buffer;
    ssize_t     bytes_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
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
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return (str);
}

//extraia prox linha (com '\n' se existir) retorna nova str apenas com essa linha

char    *ft_next_line(char *str)
{
    char    *new;
    int     i;
	int		len;

    if (!str || str[0] == 0)
        return (NULL);

    len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
    new = (char *)malloc(sizeof(char) * (len + 1));
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

//remove a linha ja retornada do buffer, retorna buffer atualizado

char    *ft_rem_line(char *line)
{
    char    *str;
    int i, j;

    if (!line)
        return (NULL);
    i = 0;
    j = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (!line[i])
        return (free(line), NULL);
    str = (char *)malloc(ft_len(line) - i + 1);
    if (!str)
        return (NULL);
    i++;
    while (line[i])
        str[j++] = line[i++];
    str[j] = '\0';
    free(line);
    return (str);
}
