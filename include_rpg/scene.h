/*
** EPITECH PROJECT, 2019
** scene.h
** File description:
** scene.h
*/

#ifndef SCENE_H_
#define SCENE_H_

#include "button.h"
#include "sprite.h"
#include "sound.h"
#include "text.h"
#include "rectangle.h"
#include "lib.h"

typedef struct button_s button_t;
typedef struct text_s text_t;

typedef struct scene_s {
    text_t *text;
    button_t *button;
    sprite_t *sprite;
    sound_t *sound;
    rectangle_t *rectangle;
} scene_t;

#endif /* !SCENE_H_ */