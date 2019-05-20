/*
** EPITECH PROJECT, 2019
** monster.h
** File description:
** monster.h
*/

#ifndef MONSTER_H_
#define MONSTER_H_

#include "lib.h"
#include "sprite.h"
#include "link.h"

typedef struct monster_s {
    int ID;
    int damage;
    int health;
    int view_range;
    sfVector2f pos;
    sfVector2f dim;
    float last_hit;
    float last_anim;
    int hit_rate;
    int speed;
    sprite_t sprite;
    sfIntRect txt_rect;
    int KEY;
} monster_t;

void update_anim_slim(monster_t *m);
void update_anim_ghost(monster_t *m);
void update_anim_bird_down(monster_t *m);
void update_anim_bird_up(monster_t *m);
void update_anim_boss(monster_t *m);
sfVector2f random_disp(monster_t *monst);

void move_big_bird(sfIntRect ground, monster_t *monst_list,
    arrow_t *arrow, game_t *game);

#endif /* !MONSTER_H_ */