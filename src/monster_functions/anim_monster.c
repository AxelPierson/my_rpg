/*
** EPITECH PROJECT, 2019
** anim
** File description:
** anim
*/

#include "monster.h"
#include "zone.h"
#include "lib.h"

void update_anim_ghost(monster_t *m)
{
    float nem = sfClock_getElapsedTime(main_clock).microseconds /
        (1000000.0);

    if (m->ID != M_GHOST)
        return;
    if ((nem - m->last_anim) > 0.15) {
        m->last_anim = nem;
        if (m->txt_rect.left < 1056) {
            m->txt_rect.left += 132;
        } else
            m->txt_rect.left = 0;
    sfSprite_setTextureRect(m->sprite.sprite, m->txt_rect);
    }
}

void update_anim_bird_up(monster_t *m)
{
    float nem = sfClock_getElapsedTime(main_clock).microseconds /
        (1000000.0);

    if (m->ID != M_BIRD)
        return;
    m->txt_rect.top = 188;
    if ((nem - m->last_anim) > 0.15) {
        m->last_anim = nem;
        if (m->txt_rect.left < 376) {
            m->txt_rect.left += 188;
        } else
            m->txt_rect.left = 0;
    sfSprite_setTextureRect(m->sprite.sprite, m->txt_rect);
    }
}

void update_anim_bird_down(monster_t *m)
{
    float nem = sfClock_getElapsedTime(main_clock).microseconds /
        (1000000.0);

    if (m->ID != M_BIRD)
        return;
    m->txt_rect.top = 0;
    if ((nem - m->last_anim) > 0.15) {
        m->last_anim = nem;
        if (m->txt_rect.left < 376) {
            m->txt_rect.left += 188;
        } else
            m->txt_rect.left = 0;
    sfSprite_setTextureRect(m->sprite.sprite, m->txt_rect);
    }
}

void update_anim_slim(monster_t *m)
{
    if (m->ID > 3)
        return;
    float nem = sfClock_getElapsedTime(main_clock).microseconds /
        (1000000.0);

    if ((nem - m->last_anim) > 0.15) {
        m->last_anim = nem;
        if (m->txt_rect.left < 1120) {
            m->txt_rect.left += 80;
        } else
            m->txt_rect.left = 0;
        sfSprite_setTextureRect(m->sprite.sprite, m->txt_rect);
    }
}