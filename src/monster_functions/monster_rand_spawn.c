/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** monster_rand_spawn.c
*/

#include "lib.h"

sfVector2f monster_random_spawn(sfVector2i zone_pos, sfVector2i zone_dim)
{
    sfVector2f rdm_monst_pos = (sfVector2f){0, 0};

    rdm_monst_pos.x = rand() % (zone_pos.x + zone_dim.x - zone_pos.x)
        + zone_pos.x;
    rdm_monst_pos.y = rand() % (zone_pos.y + zone_dim.y - zone_pos.y)
        + zone_pos.y;

    return (rdm_monst_pos);
}