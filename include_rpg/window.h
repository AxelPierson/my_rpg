/*
** EPITECH PROJECT, 2019
** window.h
** File description:
** window.h
*/

#ifndef WINDOW_H
#define WINDOW_H

#include "lib.h"

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
} window_t;

#endif