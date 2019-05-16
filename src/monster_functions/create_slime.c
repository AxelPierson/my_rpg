/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_slime.c
*/

#include "monster.h"
#include "zone.h"
#include "sprite.h"
#include "animation.h"
#include "npc.h"

void init_anim_slim(monster_t *m)
{
    switch (randr(0, 15)) {
        case 0: m->txt_rect.left = 0; break;
        case 1: m->txt_rect.left = 80; break;
        case 2: m->txt_rect.left = 160; break;
        case 3: m->txt_rect.left = 240; break;
        case 4: m->txt_rect.left = 320; break;
        case 5: m->txt_rect.left = 400; break;
        case 6: m->txt_rect.left = 480; break;
        case 7: m->txt_rect.left = 560; break;
        case 8: m->txt_rect.left = 640; break;
        case 9: m->txt_rect.left = 720; break;
        case 10: m->txt_rect.left = 800; break;
        case 11: m->txt_rect.left = 880; break;
        case 12: m->txt_rect.left = 960; break;
        case 13: m->txt_rect.left = 1040; break;
        default: m->txt_rect.left = 0; break;
    }
}

void selec_rect(monster_t *m, int ID)
{
    switch (ID) {
        case M_GREY: m->txt_rect = create_rect(0, 0, 80, 80); break;
        case M_BLUE: m->txt_rect = create_rect(80, 0, 80, 80); break;
        case M_GREEN: m->txt_rect = create_rect(160, 0, 80, 80); break;
        case M_RED: m->txt_rect = create_rect(240, 0, 80, 80); break;
        default: m->txt_rect = create_rect(0, 0, 80, 80); break;
    }
    init_anim_slim(m);
}

monster_t *create_slime(int ID)
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
    new_monst->sprite = create_sprite("assets/chuchu.png",
        (sfVector2f){0.0, 0.0},
        (sfVector2f){80, 80});
    new_monst->pos = (sfVector2f){0.0, 0.0};
    new_monst->dim = (sfVector2f){80, 80};
    selec_rect(new_monst, ID);
    sfSprite_setTextureRect(new_monst->sprite.sprite, new_monst->txt_rect);
    return (new_monst);
}