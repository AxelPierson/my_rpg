/*
** EPITECH PROJECT, 2019
** link
** File description:
** link
*/

#ifndef LINK_H_
#define LINK_H_

#include "lib.h"
#include "my_rpg.h"
#include "ocarina.h"
#include "animation.h"
#include "scene.h"

typedef struct arrow_s {
    ocarina_t *ocarina;
    int nbr;
    int state;
    int dir;
    int speed;
    sfSprite *spr;
    sfTexture *txt;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f hit;
} arrow_t;

typedef struct link_s {
    arrow_t *arrow;
    ocarina_t *ocarina;
    int event;
    sfSound **snd;
    sfSprite *spr;
    sfTexture *txt;
    sfIntRect rect;
    anim_t **anim;
    int status;
    sfVector2f pos;
    sfVector2f dim;
    int previous_anim;
    float last_anim;
    float speed;
    sfIntRect ground;
    sfVector2f quarter;
    int color_selected;
} link_t;

link_t *create_link(sfColor color);

void draw_link(link_t *link, window_t *win, void *extra);
void attack_anim(link_t *link);
void bow_anim(link_t *link);
void death_anim(link_t *link);
void update_walk(link_t *link, int bow);
void change_rect(int anim_nbr, link_t *link);

int check_collision(scene_t *game_scene, link_t *link, int move, float disp);
int collide(sfVector2f new_link_pos, sfVector2f obstacle_pos);
sfSound **create_sound_tab(void);

arrow_t *create_arrow(void);
void fire_bow(link_t *link);
void update_arrow(link_t *link);

#endif /* !LINK_H_ */
