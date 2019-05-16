/*
** EPITECH PROJECT, 2019
** bird
** File description:
** bird
*/

#include "monster.h"
#include "zone.h"
#include "sprite.h"
#include "animation.h"
#include "npc.h"

monster_t *create_big_bird(int ID)
{
    monster_t *new_monst = malloc(sizeof(monster_t));

    new_monst->damage = 0.5;
    new_monst->health = 6;
    new_monst->speed = 1;
    new_monst->view_range = 0;
    new_monst->last_hit = 0;
    new_monst->hit_rate = 2;
    new_monst->last_anim = 0.0;
    new_monst->ID = ID;
    new_monst->txt_rect = create_rect(0, 0, 188, 188);
    new_monst->sprite = create_sprite("assets/bird.png",
        (sfVector2f){0.0, 0.0},
        (sfVector2f){188, 188});
    new_monst->pos = (sfVector2f){2096.0, 1152.0};
    new_monst->dim = (sfVector2f){188, 188};
    sfSprite_setTextureRect(new_monst->sprite.sprite, new_monst->txt_rect);
    return (new_monst);
}