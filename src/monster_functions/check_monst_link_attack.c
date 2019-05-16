/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** sword_dir.c
*/

#include "lib.h"
#include "monster.h"
#include "link.h"
#include "zone.h"

int dir_in_angle_range(int ID_dir, double angle, float dir_x)
{
    switch (ID_dir) {
        case 0: if (angle > 0)
                    return (1);
            break;
        case 1: if (angle < 0)
                    return (1);
            break;
        case 2: if (dir_x < 0)
                    return (1);
            break;
        case 3: if (dir_x > 0)
                    return (1);
            break;
        default:
            break;
    }
    return (0);
}

int sword_dir(link_t *link, sfVector2f dir)
{
    double rad = cos(-dir.x) / sin(-dir.y);

    return (dir_in_angle_range(link->previous_anim - 4, rad, dir.x));
}

void check_monster_attack(link_t *link, monster_t *monst)
{
    if (main_time - (float)monst->last_hit > monst->hit_rate &&
    link->status == L_ALIVE) {
        monst->last_hit = main_time;
        link->status = L_DAMAGE;
    }
}

void check_monst_link_attack(link_t *link, monster_t *monst,
sfVector3f dist_dir)
{
    if (link->event == 1 &&
    sword_dir(link, (sfVector2f){dist_dir.y, dist_dir.z}) == 1) {
        monst->health -= 1;
        monst->pos.x += (dist_dir.y * 20);
        monst->pos.y += (dist_dir.z * 20);
    }
    if (dist_dir.x < 100) {
        check_monster_attack(link, monst);
    }
}