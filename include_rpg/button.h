/*
** EPITECH PROJECT, 2019
** button.h
** File description:
** button.h
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "my_rpg.h"
#include "game.h"

typedef struct scene_s scene_t;

typedef struct button_s {
    sfTexture *tex0;
    sfSprite *sprite0;
    sfTexture *tex1;
    sfSprite *sprite1;
    sfVector2f size;
    int button_role;
    sfMusic *sound;
    int (*callback)(game_t *game, window_t *window, void *extra);
} button_t;

#endif /* !BUTTON_H_ */