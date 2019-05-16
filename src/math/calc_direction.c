/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** calc_direction.c
*/

#include "lib.h"
#include "sprite.h"

sfVector2f calc_dir(sfVector2f pos1, sfVector2f pos2, sfVector2f *dim,
float distance)
{
    sfVector2f direction = {(float)((pos1.x + dim[0].x / 2) -
        (pos2.x + dim[1].x / 2)) / distance,
        (float)((pos1.y + dim[0].y / 2) -
        (pos2.y + dim[1].y / 2)) / distance};
    return (direction);
}