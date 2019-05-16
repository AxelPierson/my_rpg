/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** check_tile_collision.c
*/

#include "lib.h"
#include "globals.h"
#include "collision.h"
#include "zone.h"

int check_tile_collision(sfVector2f monst_pos)
{
    sfVector2i tile_pos = (sfVector2i){monst_pos.x / 16, monst_pos.y / 16};

    for (int i = tile_pos.x; i <= tile_pos.x + 1; i += 1) {
        for (int j = tile_pos.y; j <= tile_pos.y + 1; j += 1) {
            if (map_test[j][i] != 0) {
                    return (1);
            }
        }
    }
    return (0);
}