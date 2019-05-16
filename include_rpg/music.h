/*
** EPITECH PROJECT, 2019
** music
** File description:
** music
*/

#ifndef MUSIC_H
#define MUSIC_H

#include "lib.h"

typedef struct music_s {
    sfMusic **snd;
    int actual;
    sfIntRect *zone;

} music_t;

music_t *init_music(void);
void update_music(music_t *music, sfVector2f link);

#endif