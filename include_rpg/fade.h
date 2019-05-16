/*
** EPITECH PROJECT, 2019
** fade
** File description:
** fade
*/

#ifndef FADE_H
#define FADE_H

#include "my_rpg.h"
#include "ocarina.h"
#include "animation.h"

typedef struct fade_s {
    ocarina_t *ocarina;
    int index;
    int state;
    float time;
    sfCircleShape *circle;
} fade_t;

fade_t *create_fade();
void use_fade(fade_t *fade, window_t *window);

#endif
