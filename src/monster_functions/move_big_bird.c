/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** move_big_bird.c
*/

#include "monster.h"
#include "lib.h"
#include "globals.h"
#include "link.h"
#include "npc.h"

void hit_big_bird(monster_t *monst, arrow_t *arrow, game_t *game)
{
    if (monst->health > 0 && arrow->hit.x >= monst->pos.x * 4.3 &&
    arrow->hit.x <= monst->pos.x * 4.3 + monst->dim.x && arrow->hit.y >=
    monst->pos.y * 4.3 && arrow->hit.y <= monst->pos.y * 4.3 + monst->dim.y) {
        arrow->state = 0;
        monst->health -= 2;
        game->pop->npc[3]->state = 7;
    }
}

void move_big_bird(sfIntRect ground, monster_t *monst,
arrow_t *arrow, game_t *game)
{
    static float move_y = -1.0;
    static float last_turn = 0.0;

    if (main_time - last_turn > 6.0) {
        move_y *= -1.0;
        last_turn = main_time;
    }
    if (move_y > 0)
        update_anim_bird_up(monst);
    else
        update_anim_bird_down(monst);
    hit_big_bird(monst, arrow, game);
    monst->pos.y += ((float)monst->speed) * move_y / DT;
    sfSprite_setPosition(monst->sprite.sprite, (sfVector2f){(float)monst->pos.x
    * 4.3 - ground.left * 4.3, (float)monst->pos.y * 4.3 - ground.top * 4.3});
}