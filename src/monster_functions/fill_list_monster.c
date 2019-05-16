/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** fill_list_monster.c
*/

#include "monster.h"
#include "zone.h"
#include "lib.h"
#include "npc.h"

void fill_list_monster(zone_t *zone)
{
    switch (zone->ID) {
        case 1:case 2:case 5: for (int i = 0; i < (zone->tile_dim.x * zone->
            tile_dim.y / (240 * 135) * 200); i += 1)
                add_elem(zone->monst_list, (void *)create_slime(randr(0, 4)));
        break;
        case 3:
            add_elem(zone->monst_list, (void *)create_big_bird(M_BIRD)); break;
        case 4: for (int i = 0; i < (zone->tile_dim.x * zone->tile_dim.y /
            (240 * 135) * 200); i += 1)
                add_elem(zone->monst_list, (void *)create_ghost(M_GHOST));
        break;
        case 6: for (int i = 0; i < 10; i += 1)
                add_elem(zone->monst_list, (void *)create_slime(randr(0, 4)));
            ((monster_t *)zone->monst_list->array[zone->monst_list->nb_elem -
            1])->ID = M_BOSS;
            sfSprite_setColor(((monster_t *)zone->monst_list->
            array[zone->monst_list->
            nb_elem - 1])->sprite.sprite, (sfColor){20, 20, 20, 255}); break;
        default: break;
    }
}