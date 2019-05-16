/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** check_current_zone.c
*/

#include "lib.h"
#include "monster.h"
#include "zone.h"
#include "window.h"

void draw_monsters(window_t *window, zone_t *zone)
{
    for (int j = zone->monst_list->nb_elem - 1; j >= 0; j -= 1) {
        monster_t *temp = (monster_t *)zone->monst_list->array[j];
        if (temp->health > 0) {
            sfRenderWindow_drawSprite(window->window,
            temp->sprite.sprite, NULL);
        }
    }
}

void check_current_zone(window_t *window, arraylist_t *zones)
{
    for (int i = zones->nb_elem - 1; i >= 0; i -= 1) {
        if (((zone_t *)zones->array[i])->status == 1) {
            draw_monsters(window, (zone_t *)zones->array[i]);
        }
    }
}