/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_zone_list.c
*/

#include "zone.h"

zone_t *create_zone(sfVector2f zone_pos, sfVector2f zone_dim, int zone_ID)
{
    zone_t *new_zone = malloc(sizeof(zone_t));

    new_zone->tile_pos = zone_pos;
    new_zone->tile_dim = zone_dim;
    new_zone->pos = (sfVector2f){zone_pos.x * 16.0, zone_pos.y * 16.0};
    new_zone->dim = (sfVector2f){zone_dim.x * 16.0, zone_dim.y * 16.0};
    new_zone->ID = zone_ID;
    new_zone->status = 0;
    new_zone->monst_list = create_list(50);

    fill_list_monster(new_zone);

    return (new_zone);
}

arraylist_t *create_zone_list(int size)
{
    arraylist_t *zone_list = create_list(size);

    add_elem(zone_list, (void *)create_zone((sfVector2f){21.0, 59.0},
        (sfVector2f){44, 43}, 1));
    add_elem(zone_list, (void *)create_zone((sfVector2f){27.0, 37.0},
        (sfVector2f){40, 22}, 2));
    add_elem(zone_list, (void *)create_zone((sfVector2f){79.0, 68.0},
        (sfVector2f){44, 32}, 3));
    add_elem(zone_list, (void *)create_zone((sfVector2f){141.0, 8.0},
        (sfVector2f){52, 60}, 4));
    add_elem(zone_list, (void *)create_zone((sfVector2f){197.0, 36.0},
        (sfVector2f){29, 43}, 5));
    add_elem(zone_list, (void *)create_zone((sfVector2f){200.0, 8.0},
        (sfVector2f){28, 28}, 6));
    return (zone_list);
}