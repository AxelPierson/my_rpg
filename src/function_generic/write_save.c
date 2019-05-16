/*
** EPITECH PROJECT, 2019
** w
** File description:
** w
*/

#include "my_rpg.h"

void write_bow(int fd, game_t *game)
{
    char *nb_a = int_char(game->link->arrow->nbr);

    if (game->ui.arrow.drawable == true)
    write(fd, "1", 1);
    else
    write(fd, "0", 1);
    write(fd, ";", 1);
    write(fd, nb_a, my_strlen(nb_a));
    free(nb_a);
}

void write_save(game_t *game)
{
    int fd = open("src/backup", O_WRONLY | O_TRUNC);
    char *line = NULL;

    if (fd < 0)
        return;
    line = strcopy(cat(cat(int_char(game->link->color_selected), ";"),
        int_char(game->checkpoint)));
    write(fd, line, my_strlen(line));
    write(fd, ";", 1);
    if (game->ui.item[2].status == true)
    write(fd, "1", 1);
    else
    write(fd, "0", 1);
    write(fd, ";", 1);
    write_bow(fd, game);
    close(fd);
    free(line);
}