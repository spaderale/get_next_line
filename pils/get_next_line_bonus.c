#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
    static char *str[FD_MAX];
    char        *out;

    if(BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_MAX)
        return NULL;
    str[fd] = line_allocation(fd, str[fd]);
    if (!str[fd])
        return NULL;
    out = ft_next_line(str[fd]);
    str[fd] = ft_rem_line(str[fd]);
    return (out);
}
