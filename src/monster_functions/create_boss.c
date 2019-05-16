/*
** EPITECH PROJECT, 2019
** boss
** File description:
** boss
*/

#include "monster.h"
#include "zone.h"
#include "sprite.h"
#include "animation.h"
#include "npc.h"
#include "globals.h"

void update_anim_boss(monster_t *m)
{
    float nem = sfClock_getElapsedTime(main_clock).microseconds /
        (1000000.0);

    if (m->ID != M_BOSS)
        return;
    if (m->health <= 0)
        end = true;
    if ((nem - m->last_anim) > 0.15) {
        m->last_anim = nem;
        if (m->txt_rect.left < 1120) {
            m->txt_rect.left += 80;
        } else
            m->txt_rect.left = 0;
    sfSprite_setTextureRect(m->sprite.sprite, m->txt_rect);
    }
}

monster_t *create_boss(int ID)
{
    monster_t *new_monst = malloc(sizeof(monster_t));

    new_monst->damage = 0.5;
    new_monst->health = 2;
    new_monst->speed = 1;
    new_monst->view_range = 400;
    new_monst->last_hit = 0;
    new_monst->hit_rate = 2;
    new_monst->last_anim = 0.0;
    new_monst->ID = ID;
    new_monst->txt_rect = create_rect(0, 0, 528, 528);
    new_monst->sprite = create_sprite("assets/boss.png",
        (sfVector2f){0.0, 0.0},
        (sfVector2f){528.0, 528.0});
    new_monst->pos = (sfVector2f){3424.0, 240.0};
    new_monst->dim = (sfVector2f){528.0, 528.0};
    sfSprite_setTextureRect(new_monst->sprite.sprite, new_monst->txt_rect);
    return (new_monst);
}