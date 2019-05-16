/*
** EPITECH PROJECT, 2019
** link attack animation
** File description:
** link_attack
*/

#include "animation.h"
#include "enum.h"
#include "link.h"
#include "globals.h"

unsigned int randr(unsigned int min, unsigned int max);

void attack_sound(link_t *link)
{
    unsigned int rnd = randr(1, 4);
    if (link->previous_anim < 4) {
        if (sound_activated  == true) {
            sfSound_play(link->snd[rnd]);
            sfSound_play(link->snd[0]);
        }
        link->previous_anim += 4;
    }
    link->rect.top = link->anim[link->previous_anim]->coord.y;
    link->rect.left = link->anim[link->previous_anim]->coord.x;
    link->rect.width = link->anim[link->previous_anim]->size.x;
    link->rect.height = link->anim[link->previous_anim]->size.y;
}

void attack_anim(link_t *link)
{
    attack_sound(link);
    if (link->anim[link->previous_anim]->index >=
        link->anim[link->previous_anim]->nbr) {
        link->anim[link->previous_anim]->coord.x =
            link->anim[link->previous_anim]->init_pos;
        link->anim[link->previous_anim]->index = 0;
        link->previous_anim -= 4;
    } else {
        link->anim[link->previous_anim]->coord.x +=
            link->anim[link->previous_anim]->size.x;
        link->anim[link->previous_anim]->index += 1;
    }
    link->last_anim = link->ocarina->time;
}

void bow_anim(link_t *link)
{
    if (link->previous_anim < 4)
        link->previous_anim += 8;
    if (link->anim[link->previous_anim]->index == 5)
        fire_bow(link);
    link->rect.top = link->anim[link->previous_anim]->coord.y;
    link->rect.left = link->anim[link->previous_anim]->coord.x;
    link->rect.width = link->anim[link->previous_anim]->size.x;
    link->rect.height = link->anim[link->previous_anim]->size.y;
    if (link->anim[link->previous_anim]->index >= link->anim[link->
    previous_anim]->nbr) {
        link->anim[link->previous_anim]->coord.x = link->anim[link->
            previous_anim]->init_pos;
        link->anim[link->previous_anim]->index = 0;
        link->previous_anim -= 8;
    } else {
        link->anim[link->previous_anim]->coord.x += link->anim[link->
            previous_anim]->size.x;
        link->anim[link->previous_anim]->index += 1;
    }
    link->last_anim = link->ocarina->time;
}

void death_anim(link_t *link)
{
    if (link->previous_anim < 4) {
        link->previous_anim = 12;
    }
    link->rect.top = link->anim[link->previous_anim]->coord.y;
    link->rect.left = link->anim[link->previous_anim]->coord.x;
    link->rect.width = link->anim[link->previous_anim]->size.x;
    link->rect.height = link->anim[link->previous_anim]->size.y;
    if (link->anim[link->previous_anim]->index >=
        link->anim[link->previous_anim]->nbr) {
        link->anim[link->previous_anim]->coord.x =
            link->anim[link->previous_anim]->init_pos;
        link->anim[link->previous_anim]->index = 0;
    } else {
        link->anim[link->previous_anim]->coord.x +=
            link->anim[link->previous_anim]->size.x;
        link->anim[link->previous_anim]->index += 1;
    }
    link->last_anim = link->ocarina->time;
}