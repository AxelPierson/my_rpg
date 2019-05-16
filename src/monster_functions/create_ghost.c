/*
** EPITECH PROJECT, 2019
** ghost
** File description:
** ghost
*/

#include "monster.h"
#include "zone.h"
#include "sprite.h"
#include "animation.h"
#include "npc.h"

void init_anim_ghost(monster_t *m)
{
    switch (randr(0, 9)) {
        case 0: m->txt_rect.left = 0; break;
        case 1: m->txt_rect.left = 132; break;
        case 2: m->txt_rect.left = 264; break;
        case 3: m->txt_rect.left = 396; break;
        case 4: m->txt_rect.left = 528; break;
        case 5: m->txt_rect.left = 660; break;
        case 6: m->txt_rect.left = 792; break;
        case 7: m->txt_rect.left = 924; break;
        case 8: m->txt_rect.left = 1056; break;
        default: m->txt_rect.left = 0; break;
    }
}

monster_t *create_ghost(int ID)
{
    (void)ID;
    monster_t *new_monst = malloc(sizeof(monster_t));

    new_monst->damage = 0.5;
    new_monst->health = 2;
    new_monst->speed = 1;
    new_monst->view_range = 300;
    new_monst->last_hit = 0;
    new_monst->hit_rate = 2;
    new_monst->last_anim = 0.0;
    new_monst->ID = ID;
    new_monst->sprite = create_sprite("assets/g_laby.png",
        (sfVector2f){0.0, 0.0},
        (sfVector2f){132, 132});
    new_monst->txt_rect = create_rect(0, 0, 132, 132);
    new_monst->pos = (sfVector2f){0.0, 0.0};
    new_monst->dim = (sfVector2f){132, 132};
    init_anim_ghost(new_monst);
    sfSprite_setTextureRect(new_monst->sprite.sprite, new_monst->txt_rect);
    return (new_monst);
}