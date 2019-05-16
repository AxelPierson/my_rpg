/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** sprite.h
*/

#ifndef SPRITE_H_
#define SPRITE_H_

#include "lib.h"

typedef struct sprite_s {
    sfTexture *tex;
    sfSprite *sprite;
    sfVector2f size;
} sprite_t;

sprite_t create_sprite(char *path, sfVector2f position, sfVector2f size);

#endif