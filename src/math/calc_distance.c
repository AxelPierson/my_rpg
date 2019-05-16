/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** calc_distance.c
*/

#include "lib.h"
#include "sprite.h"

float calc_dist(sfVector2f pos1, sfVector2f dim1, sfVector2f pos2,
sfVector2f dim2)
{
    float distance = 0;

    sfVector2f mid1 = (sfVector2f){pos1.x + dim1.x / 2.0,
        pos1.y + dim1.y / 2.0};
    sfVector2f mid2 = (sfVector2f){pos2.x + dim2.x / 2.0,
        pos2.y + dim2.y / 2.0};

    distance = sqrt(pow((mid2.x - mid1.x), 2) +
                    pow((mid2.y - mid1.y), 2));

    return (distance);
}