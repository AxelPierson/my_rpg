/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** check_monst_collision.c
*/

#include "lib.h"
#include "link.h"
#include "monster.h"
#include "collision.h"
#include "zone.h"
#include "globals.h"

int is_in_zone(int i, int j, zone_t *zone)
{
    if (i > zone->tile_pos.x && i < zone->tile_pos.x + zone->tile_dim.x &&
    j > zone->tile_pos.y && j < zone->tile_pos.y + zone->tile_dim.y) {
            return (1);
    }
    return (0);
}

sfVector2f predic_next_pos(sfVector2f init_pos, sfVector2f dir)
{
    sfVector2f new_pos = (sfVector2f){init_pos.x + (dir.x * 1.5),
        init_pos.y + (dir.y * 1.5)};

    return (new_pos);
}

int check_each_tile(int *tile_pos, zone_t *zone, monster_t *monst,
sfVector2f next_pos)
{
    if (map_test[tile_pos[1]][tile_pos[0]] != 0 && is_in_zone(tile_pos[0],
    tile_pos[1], zone) == 1) {
        sfVector2f new_pos = {tile_pos[0] / 240.0 * 3840.0,
            tile_pos[1] / 135.0 * 2160.0};
        if (hit_obstacle(next_pos, monst->dim, (sfVector2f){new_pos.x * 4.3,
        new_pos.y * 4.3}, (sfVector2f){16, 16}) == 1) {
            return (1);
        }
    }
    return (0);
}

int check_monst_collision(monster_t *monst, link_t *link,
sfVector2f *pix_pos_dir, zone_t *zone)
{
    sfVector2f next_pos = predic_next_pos(pix_pos_dir[1],
        pix_pos_dir[2]);

    if (hit_obstacle(next_pos, monst->dim, pix_pos_dir[0], link->dim) == 1) {
        return (1);
    }
    if (zone->ID == 4) {
        return (0);
    }
    for (int i = 0; i < 240; i += 1) {
        for (int j = 0; j < 135; j += 1) {
            if (check_each_tile((int[2]){i, j}, zone, monst, next_pos) == 1)
                return (1);
        }
    }
    return (0);
}