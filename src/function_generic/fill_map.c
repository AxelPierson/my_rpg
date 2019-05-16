/*
** EPITECH PROJECT, 2019
** fill
** File description:
** fill
*/

#include "my_rpg.h"
#include "globals.h"

void new_map_line(int i, char **map_array)
{
    int *map_line = malloc(sizeof(int) * 240);
    int j = 0;

    for (; map_array[j + 1] != NULL; j += 1) {
        int numb = my_getnbr(map_array[j]);
        map_line[j] = numb;
    }
    map_line[j] = 0;
    map_test[i] = map_line;
}

int fill_map(void)
{
    FILE *fd =  fopen("src/map.txt", "r");
    char *line = NULL;
    char **map_array = NULL;
    size_t size = 0;
    char *buf = NULL;

    if (fd == NULL)
        return (84);
    for (int i = 0; getline(&line, &size, fd) >= 0; i += 1) {
        buf = strcopy(line);
        map_array = special_str_tab(buf, ',');
        new_map_line(i, map_array);
        for (int f = 0; map_array[f] != NULL; f++)
            free(map_array[f]);
        free(map_array);
    }
    free(line);
    fclose(fd);
    return (0);
}