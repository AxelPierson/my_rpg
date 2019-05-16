/*
** EPITECH PROJECT, 2019
** animation
** File description:
** animation
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include "lib.h"

typedef struct anim_s {
    sfVector2f coord;
    int init_pos;
    sfVector2f size;
    int index;
    int nbr;
} anim_t;

sfIntRect create_rect(int top, int left, int width, int height);
anim_t **create_link_anim_tab(void);

#endif