/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** complete_monster_list.c
*/

#include "zone.h"

sfVector2f monster_random_spawn(sfVector2i zone_pos, sfVector2i zone_dim);

sfVector2f convert_pos_map_ground(sfVector2f zone_pos, sfIntRect ground)
{
    sfVector2f new_pos = (sfVector2f){0, 0};

    new_pos.x = (zone_pos.x - ground.left) * 4.3;
    new_pos.y = (zone_pos.y - ground.top) * 4.3;

    return (new_pos);
}

void set_boss_pos(monster_t *boss, sfIntRect ground)
{
    boss->pos = (sfVector2f){3424.0, 240.0};
    sfSprite_setPosition(boss->sprite.sprite,
        convert_pos_map_ground(boss->pos, ground));
}

void complete_monster_pos(zone_t *zone, arraylist_t *monst_list,
sfIntRect ground)
{
    for (int i = monst_list->nb_elem - 1; i >= 0;) {
        monster_t *temp = (monster_t *)monst_list->array[i];
        temp->pos = monster_random_spawn((sfVector2i){zone->pos.x,
            zone->pos.y},
            (sfVector2i){zone->dim.x, zone->dim.y});
        if (zone->ID == 4 || check_tile_collision(temp->pos) == 0) {
            sfVector2f test = convert_pos_map_ground(temp->pos, ground);
            sfSprite_setPosition(temp->sprite.sprite, test);
            i -= 1;
        }
        if (temp->ID == M_BOSS)
            set_boss_pos(temp, ground);
        temp->health = 2;
    }
}

void complete_monster_list(sfIntRect ground, arraylist_t *zone_list)
{
    for (int i = zone_list->nb_elem - 1; i >= 0; i -= 1) {
        zone_t *temp_zone = (zone_t *)zone_list->array[i];
        complete_monster_pos(temp_zone, temp_zone->monst_list, ground);
    }
}