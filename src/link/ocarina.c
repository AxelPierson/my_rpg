/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** ocarina.c
*/

#include "animation.h"
#include "ocarina.h"

ocarina_t *create_ocarina(void)
{
    ocarina_t *ocarina = malloc(sizeof(ocarina_t));

    ocarina->clock = sfClock_create();
    ocarina->time = 0.0;

    return (ocarina);
}