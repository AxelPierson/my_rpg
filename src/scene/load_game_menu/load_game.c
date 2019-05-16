/*
** EPITECH PROJECT, 2019
** load
** File description:
** load
*/

#include "my_rpg.h"
#include "globals.h"

int is_backup_damaged(char *backup)
{
    int index = true;
    int it = 0;
    char **array = special_str_tab(backup, ';');

    for (; array[it] != NULL; it++);
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    if (it != 5)
        index = false;
    return (index);
}

char *get_file(void)
{
    FILE *fd = fopen("src/backup", "r");
    char *line = NULL;
    size_t size = 0;

    if (fd == NULL)
        return (NULL);
    for (int i = 0; getline(&line, &size, fd) >= 0; i += 1) {
        return (line);
    }
    fclose(fd);
    return (line);
}

int load_stuff(game_t *game, char **save)
{
    int index = 0;

    index = my_getnbr(save[2]);
    if (index == 1)
        get_lock(game);
    index = my_getnbr(save[3]);
    if (index == 1)
        get_bow(game);
    index = my_getnbr(save[4]);
    game->link->arrow->nbr = index;
    update_arrow_counter(game);
    return (true);
}

void load_link(game_t *game, char **save)
{
    int index = 0;
    sfVector2f pos = (sfVector2f){0, 0};

    index = my_getnbr(save[0]);
    switch (index) {
        case 0: game->link = create_link((sfColor){255, 255, 255, 255}); break;
        case 1: game->link = create_link((sfColor){75, 75, 75, 255}); break;
        default: game->link = create_link((sfColor){75, 75, 75, 255}); break;
    }
    index = my_getnbr(save[1]);
    game->checkpoint = index;
    pos = game->sign[index].position;
    spawn_pos.top = (pos.y / 4.3) - 100;
    spawn_pos.left = (pos.x / 4.3) - 215;
    sfSprite_setTextureRect(game->scene[S_GAME].sprite[0].sprite, spawn_pos);
    game->link->ground = spawn_pos;
    load_stuff(game, save);
}

int load_game(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    char *line = get_file();
    char **save = NULL;

    if (line == NULL ||
        is_backup_damaged(line) == false)
        error_load_game(game, window);
    else if (str_ncomp(line, "NULL", 4) == 1)
        error_load_game(game, window);
    else {
        save = str_to_word_array(line, ';');
        load_link(game, save);
        play_game(game, window);
    }
    free(line);
    return (true);
}