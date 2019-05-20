/*
** EPITECH PROJECT, 2019
** zones.h
** File description:
** zones.h
*/

#ifndef ZONES_H_
#define ZONES_H_

#include "lib.h"
#include "../src/arraylist/include_vector/vector.h"
#include "monster.h"
#include "window.h"
#include "link.h"

typedef struct zone_s {
    sfVector2f pos;
    sfVector2f dim;
    sfVector2f tile_pos;
    sfVector2f tile_dim;
    int ID;
    int status;
    arraylist_t *monst_list;
    float timezone;
} zone_t;


arraylist_t *create_zone_list(int size);
void fill_list_monster(zone_t *new_zone);
monster_t *create_slime(int ID);
monster_t *create_boss(int ID);
monster_t *create_ghost(int ID);
monster_t *create_big_bird(int ID);
void fill_list_monster(zone_t *new_zone);

void complete_monster_pos(zone_t *zone, arraylist_t *monst_list,
sfIntRect ground);
void complete_monster_list(sfIntRect ground, arraylist_t *zone_list);
void update_monst_list(sfIntRect ground, arraylist_t *zone_list,
    link_t *link, game_t *game);
int check_tile_collision(sfVector2f monst_pos);

void check_current_zone(window_t *window, arraylist_t *zones);
void update_zone(arraylist_t *zones, link_t *link);

#endif /* !ZONES_H_ */