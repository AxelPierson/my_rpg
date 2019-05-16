/*
** EPITECH PROJECT, 2019
** arrow
** File description:
** arrow
*/

#include "lib.h"
#include "link.h"
#include "zone.h"

arrow_t *create_arrow(void)
{
    arrow_t *arrow = malloc(sizeof(arrow_t));

    arrow->pos = (sfVector2f){0, 0};
    arrow->state = 0;
    arrow->dir = 0;
    arrow->speed = 20;
    arrow->nbr = 25;
    arrow->ocarina = create_ocarina();
    arrow->txt = sfTexture_createFromFile("assets/arrow.png", NULL);
    arrow->spr = sfSprite_create();
    sfSprite_setTexture(arrow->spr, arrow->txt, sfTrue);
    sfSprite_setScale(arrow->spr, (sfVector2f){3.4, 3.4});
    arrow->rect.height = 15;
    arrow->rect.width = 15;
    arrow->rect.top = 0;
    arrow->rect.left = 0;
    return (arrow);
}

void arrow_pos(link_t *link)
{
    switch (link->arrow->dir) {
        case 0:
            link->arrow->pos.x -= 30;
            link->arrow->pos.y -= 40;
            break;
        case 1:
            link->arrow->pos.x -= 15;
            break;
        case 2:
            link->arrow->pos.y -= 20;
            link->arrow->pos.x -= 40;
            break;
        case 3:
            link->arrow->pos.y -= 20;
            break;
    }
}

void fire_bow(link_t *link)
{
    sfClock_restart(link->arrow->ocarina->clock);
    if (sound_activated  == true)
        sfSound_play(link->snd[4]);
    link->arrow->state = 1;
    link->arrow->nbr -= 1;
    link->arrow->dir = link->previous_anim - 8;
    link->arrow->rect.top = link->arrow->dir * 15;
    link->arrow->pos = (sfVector2f){link->pos.x * 4.3, link->pos.y * 4.3};
    arrow_pos(link);
    sfSprite_setTextureRect(link->arrow->spr, link->arrow->rect);
}

void arrow_switch(arrow_t *arrow)
{
    arrow->ocarina->time =
        sfClock_getElapsedTime(arrow->ocarina->clock).microseconds / 1000000.0;
    switch (arrow->dir) {
        case 0: arrow->pos.y -= arrow->speed;
            arrow->hit = (sfVector2f){arrow->pos.x + 27, arrow->pos.y + 10};
            break;
        case 1: arrow->pos.y += arrow->speed;
            arrow->hit = (sfVector2f){arrow->pos.x + 27, arrow->pos.y + 44};
            break;
        case 2: arrow->pos.x -= arrow->speed;
            arrow->hit = (sfVector2f){arrow->pos.x + 10, arrow->pos.y + 27};
            break;
        case 3: arrow->pos.x += arrow->speed;
            arrow->hit = (sfVector2f){arrow->pos.x + 44, arrow->pos.y + 27};
            break;
    }
}

void update_arrow(link_t *link)
{
    if (link->arrow->state == 1) {
        arrow_switch(link->arrow);
        sfSprite_setPosition(link->arrow->spr,
            (sfVector2f){link->arrow->pos.x - link->ground.left *
            4.3, link->arrow->pos.y - link->ground.top * 4.3});
        if (link->arrow->ocarina->time > 1)
            link->arrow->state = 0;
    }
}