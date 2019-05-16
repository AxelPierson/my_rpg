/*
** EPITECH PROJECT, 2019
** ocarina.h
** File description:
** ocarina.h
*/

#ifndef OCARINA_H_
#define OCARINA_H_

#include "lib.h"

typedef struct ocarina_s {
    sfClock *clock;
    float time;
} ocarina_t;

ocarina_t *create_ocarina();

#endif /* !OCARINA_H_ */