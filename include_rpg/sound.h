/*
** EPITECH PROJECT, 2019
** sound.h
** File description:
** sound.h
*/

#ifndef SOUND_H_
#define SOUND_H_

#include "my_rpg.h"

typedef struct sound_s {
    int volume;
    int is_sound;
    int type;
    sfMusic *music;
} sound_t;

#endif /* !SOUND_H_ */