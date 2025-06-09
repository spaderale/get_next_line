#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	int		ended1 = 0;
	int		ended2 = 0;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("Erro ao abrir arquivos.\n");
		return (1);
	}
	while (!ended1 || !ended2)
	{
		if (!ended1)
		{
			line1 = get_next_line(fd1);
			if (line1)
			{
				printf("file1: %s", line1);
				free(line1);
			}
			else
				ended1 = 1;
		}
		if (!ended2)
		{
			line2 = get_next_line(fd2);
			if (line2)
			{
				printf("file2: %s", line2);
				free(line2);
			}
			else
				ended2 = 1;
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
