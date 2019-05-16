/*
** EPITECH PROJECT, 2019
** link walk
** File description:
** link_walk
*/

#include "animation.h"
#include "link.h"
#include "enum.h"

void reset_rect(link_t *link)
{
    int prev = link->previous_anim;
    link->anim[prev]->coord.x =
            link->anim[prev]->init_pos;
            link->rect.top = link->anim[prev]->coord.y;
    link->rect.left = link->anim[prev]->coord.x;
    link->rect.width = link->anim[prev]->size.x;
    link->rect.height = link->anim[prev]->size.y;
}

void choose_anim(int index, link_t *link, int bow)
{
    float passing_time = link->ocarina->time - link->last_anim;

    if (link->status == L_DEAD) {
        if (passing_time > 0.1)
            death_anim(link);
    } else if (((sfKeyboard_isKeyPressed(sfKeyQ) || link->previous_anim > 7) &&
        link->arrow->state == 0 && link->arrow->nbr > 0 && bow)) {
        if (passing_time > 0.2)
            bow_anim(link);
    } else if (link->event == 1 || link->previous_anim >= 4 ) {
        if (passing_time > 0.033)
            attack_anim(link);
    } else if (index >= 0) {
        if (passing_time > 0.1)
            change_rect(index, link);
        link->previous_anim = index;
    } else
        reset_rect(link);
    sfSprite_setTextureRect(link->spr, link->rect);
}

void update_walk(link_t *link, int bow)
{
    int index = -1;

    if (sfKeyboard_isKeyPressed(sfKeyUp)) index = 0;
    if (sfKeyboard_isKeyPressed(sfKeyDown)) index = 1;
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) index = 2;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) index = 3;
    choose_anim(index, link, bow);
}