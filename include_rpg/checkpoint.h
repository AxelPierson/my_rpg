/*
** EPITECH PROJECT, 2019
** check
** File description:
** check
*/

#ifndef CHECKPOINT_H_
#define CHECKPOINT_H_

#include "lib.h"

typedef struct checkpoint_s{
    sfRectangleShape *shape;
    sfVector2f position;
    sfVector2f size;
} checkpoint_t;

#endif /* !CHECKPOINT_H_ */