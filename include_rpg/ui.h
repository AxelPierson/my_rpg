/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory
*/

#ifndef UI_H_
#define UI_H_

#include "lib.h"
#include "sprite.h"

typedef struct counter_s {
    sfText *text;
    sfFont *font;
    int n;
    int drawable;
    int status;
} counter_t;

typedef struct heart_s {
    sfSprite *spr;
    sfTexture *tex;
    int status;
} heart_t;

typedef struct item_s {
    sfSprite *spr;
    sfTexture *tex;
    int status;
} item_t;

typedef struct icon_s {
    sfTexture *tex;
    sfSprite *sprite;
    sfVector2f size;
    int status;
} icon_t;

typedef struct ui_s {
    sfClock *regen;
    sfTexture **texture;
    heart_t *heart;
    item_t *item;
    sprite_t life;
    icon_t *icon;
    counter_t arrow;
} ui_t;
#endif /* !UI_H_ */