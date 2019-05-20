/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** update_monst_list.c
*/

#include "lib.h"
#include "monster.h"
#include "zone.h"
#include "calc_dist_dir.h"
#include "collision.h"

sfVector2f detect_link(zone_t *zone, monster_t *monst, link_t *link,
sfVector2f link_pos)
{
    sfVector2f dir = {0.0, 0.0};
    sfVector2f monst_pos = {monst->pos.x * 4.3, monst->pos.y * 4.3};

    float dist = calc_dist(link_pos, link->dim, monst_pos, monst->dim);
    if (dist < monst->view_range) {
        dir = calc_dir(link_pos, monst_pos, (sfVector2f[2]){link->dim,
            monst->dim}, dist);
        dir.x = dir.x * ((float)monst->speed) / DT;
        dir.y = dir.y * ((float)monst->speed) / DT;
        if (dist < 150 || (monst->ID == M_BOSS && dist < 400))
            check_monst_link_attack(link, monst, (sfVector3f){dist,
                -dir.x, -dir.y});
        if (check_monst_collision(monst, link, (sfVector2f[3]){link_pos,
        monst_pos, dir}, zone) == 0)
            return (dir);
    }
    return ((sfVector2f){0, 0});
}

void bow_kill(zone_t *zone, link_t *link)
{
    monster_t *m = NULL;

    if (link->arrow->state != 1)
        return;
    for (int i = 0; i < zone->monst_list->nb_elem; i++) {
        m = (monster_t *)zone->monst_list->array[i];
        if (m->health > 0 && link->arrow->hit.x >= m->pos.x * 4.3 &&
        link->arrow->hit.x <= m->pos.x * 4.3 + m->dim.x &&
        link->arrow->hit.y >= m->pos.y * 4.3 &&
        link->arrow->hit.y <= m->pos.y * 4.3 + m->dim.y
        && m->ID != M_BOSS) {
            link->arrow->state = 0;
            m->health -= 2;
        }
    }
}

void update_anim(monster_t *monst)
{
    update_anim_slim(monst);
    update_anim_ghost(monst);
    update_anim_boss(monst);
}

void update_monster(sfIntRect ground, zone_t *zone, link_t *link)
{
    sfVector2f dir = {0, 0};
    sfVector2f link_pos = {link->pos.x * 4.3 - link->dim.x / 2,
        link->pos.y * 4.3 - link->dim.y / 2};
    monster_t *monst = NULL;

    for (int i = zone->monst_list->nb_elem - 1; i >= 0; i -= 1) {
        monst = ((monster_t *)zone->monst_list->array[i]);
        if (monst->health > 0) {
            dir = detect_link(zone, monst, link, link_pos);
            if (dir.x == 0 && dir.y == 0)
                dir = random_disp(monst);
            monst->pos.x += dir.x;
            monst->pos.y += dir.y;
            sfSprite_setPosition(monst->sprite.sprite,
                (sfVector2f){(float)monst->pos.x * 4.3 - ground.left * 4.3,
                (float)monst->pos.y * 4.3 - ground.top * 4.3});
            update_anim(monst);
        }
    }
}

void update_monst_list(sfIntRect ground, arraylist_t *zone_list,
    link_t *link, game_t *game)
{
    zone_t *temp_zone = NULL;

    for (int i = zone_list->nb_elem - 1; i >= 0; i -= 1) {
        temp_zone = ((zone_t *)zone_list->array[i]);
        if (temp_zone->status == 1 && temp_zone->ID != 3) {
            update_monster(ground, (zone_t *)zone_list->array[i], link);
            bow_kill((zone_t *)zone_list->array[i], link);
        } else if (temp_zone->status == 1 && temp_zone->ID == 3)
            move_big_bird(ground, (monster_t *)temp_zone->monst_list->array[0],
                link->arrow, game);
    }
}