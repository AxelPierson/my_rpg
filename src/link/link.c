/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** link.c
*/

#include "animation.h"
#include "link.h"
#include "enum.h"
#include "globals.h"

void change_rect(int anim_nbr, link_t *link)
{
    link->rect.top = link->anim[anim_nbr]->coord.y;
    link->rect.left = link->anim[anim_nbr]->coord.x;
    link->rect.width = link->anim[anim_nbr]->size.x;
    link->rect.height = link->anim[anim_nbr]->size.y;
    if (link->anim[anim_nbr]->index >= link->anim[anim_nbr]->nbr) {
        link->anim[anim_nbr]->coord.x = link->anim[anim_nbr]->init_pos;
        link->anim[anim_nbr]->index = 0;
    } else {
        link->anim[anim_nbr]->coord.x += link->anim[anim_nbr]->size.x;
        link->anim[anim_nbr]->index += 1;
    }
    link->last_anim = link->ocarina->time;
}

void init_link(link_t *link, sfColor color)
{
    link->ocarina = create_ocarina();
    link->arrow = create_arrow();
    link->snd = create_sound_tab();
    link->status = L_ALIVE;
    link->ground = spawn_pos;
    link->txt = sfTexture_createFromFile("assets/link.png", NULL);
    link->spr = sfSprite_create();
    link->previous_anim = 3;
    sfSprite_setTexture(link->spr, link->txt, sfTrue);
    link->rect = create_rect(112, 5, 20, 28);
    sfSprite_setTextureRect(link->spr, link->rect);
    sfSprite_setColor(link->spr, color);
    sfSprite_scale(link->spr, (sfVector2f){3.4, 3.4});
    sfSprite_setPosition(link->spr, (sfVector2f){(1920 / 2) -
        (51 * 3.4) / 2, (1080 / 2) - (51 * 3.4) / 2});
    link->previous_anim = 0;
}

link_t *create_link(sfColor color)
{
    link_t *link = malloc(sizeof(link_t));

    init_link(link, color);
    link->event = 0;
    link->anim = create_link_anim_tab();
    link->last_anim = 0.2;
    link->speed = 2;
    link->quarter = (sfVector2f){(3840 / (16 * 240 * 4.3)) * 1920 / 4,
        (2160 / (16 * 135 * 4.3)) * 1080 / 4};
    link->pos = (sfVector2f){link->ground.left + link->quarter.x * 2,
                            link->ground.top + link->quarter.y * 2};
    link->dim = (sfVector2f){20.0 * 3.4, 28.0 * 3.4};
    return (link);
}