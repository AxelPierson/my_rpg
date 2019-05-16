/*
** EPITECH PROJECT, 2019
** rectangle
** File description:
** rectangle
*/

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "lib.h"

typedef struct rectangle_s {
    sfRectangleShape *shape;
} rectangle_t;

rectangle_t create_rectangle(sfVector2f
    size, sfVector2f position, sfColor color);

#endif /* !RECTANGLE_H_ */