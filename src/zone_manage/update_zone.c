/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** update_zone.c
*/

#include "zone.h"
#include "link.h"

int link_in_zone(zone_t *zone, sfVector2f link_pos)
{
    if (link_pos.x > zone->pos.x && link_pos.x < zone->pos.x + zone->dim.x &&
        link_pos.y > zone->pos.y && link_pos.y < zone->pos.y + zone->dim.y) {
            return (1);
        }
    return (0);
}

void update_zone_2(zone_t *temp_zone, link_t *link)
{
    if (temp_zone->status == 0) {
        if (temp_zone->ID != 3) {
            complete_monster_pos(temp_zone, temp_zone->monst_list,
            link->ground);
        }
        temp_zone->status = 1;
    }
}

void update_zone(arraylist_t *zones, link_t *link)
{
    zone_t *temp_zone = NULL;

    for (int i = zones->nb_elem - 1; i >= 0; i -= 1) {
        temp_zone = (zone_t *)zones->array[i];
        if (link_in_zone(temp_zone, link->pos) == 1) {
            update_zone_2(temp_zone, link);
        } else {
            (temp_zone)->status = 0;
        }
    }
}