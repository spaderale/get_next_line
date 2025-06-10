#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PROGRESS_FILE "progress.txt"
#define NFILES 2
const char *filenames[NFILES] = {"file1.txt", "file2.txt"};

int get_current_round(void)
{
    FILE *pf = fopen(PROGRESS_FILE, "r");
    int round = 0;
    if (pf)
    {
        fscanf(pf, "%d", &round);
        fclose(pf);
    }
    return round;
}

void set_next_round(int round)
{
    FILE *pf = fopen(PROGRESS_FILE, "w");
    if (pf)
    {
        fprintf(pf, "%d\n", round + 1);
        fclose(pf);
    }
}

int main(void)
{
    int round = get_current_round();
    int fds[NFILES];
    char *line = NULL;

    for (int i = 0; i < NFILES; i++)
    {
        fds[i] = open(filenames[i], O_RDONLY);
        if (fds[i] < 0)
        {
            perror(filenames[i]);
            for (int j = 0; j < i; j++) close(fds[j]);
            return 1;
        }
    }

    for (int i = 0; i < NFILES; i++)
    {
        int count = 0;
        while (count <= round)
        {
            if (line) { free(line); line = NULL; }
            line = get_next_line(fds[i]);
            if (!line)
                break;
            count++;
        }
        if (line && count == round + 1) // só printa se pegou a linha certa!
        {
            printf("Arquivo %s, linha %d: %s", filenames[i], round + 1, line);
            free(line);
        }
        else if (!line)
        {
            printf("Arquivo %s terminou.\n", filenames[i]);
        }
        close(fds[i]);
    }

    set_next_round(round);

    return 0;
}
