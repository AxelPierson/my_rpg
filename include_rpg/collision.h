/*
** EPITECH PROJECT, 2019
** collision.h
** File description:
** collision.h
*/

#ifndef COLLISION_H_
#define COLLISION_H_

#include "lib.h"
#include "monster.h"
#include "link.h"
#include "zone.h"

int collide(sfVector2f new_link_pos, sfVector2f obstacle_pos);
int is_in_range(sfVector2f new_pos, sfVector2f limit_x, sfVector2f limit_y);
int hit_obstacle(sfVector2f obs_pos, sfVector2f dim_obs, sfVector2f link_pos,
    sfVector2f dim_link);

int check_monst_collision(monster_t *monst, link_t *link,
    sfVector2f *pix_pos_dir, zone_t *zone);

void check_monst_link_attack(link_t *link, monster_t *monst,
    sfVector3f dist_dir);

#endif /* !COLLISION_H_ */