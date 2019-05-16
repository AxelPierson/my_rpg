/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** check_collision.c
*/

#include "my_rpg.h"
#include "link.h"
#include "scene.h"

int is_in_range(sfVector2f new_pos, sfVector2f limit_x, sfVector2f limit_y)
{
    if (new_pos.x > limit_x.x && new_pos.x < limit_x.y &&
        new_pos.y > limit_y.x && new_pos.y < limit_y.y) {
            return (1);
        }
    return (0);
}

int check_collision_dir_2(int *tile_pos, sfVector2f *tab_limit,
float *tab_disp, link_t *link)
{
    sfVector2f new_pos = {tile_pos[0] / 240.0 * 3840.0,
        tile_pos[1] / 135.0 * 2160.0};
    if (map_test[tile_pos[1]][tile_pos[0]] != 0 &&
    is_in_range(new_pos, tab_limit[0], tab_limit[1]) == 1) {
        if (collide((sfVector2f){link->pos.x + tab_disp[0],
        link->pos.y + tab_disp[1]}, new_pos) == 1) {
            return (0);
        }
    }
    return (1);
}

int check_collision_dir(link_t *link, float disp1, float disp2)
{
    sfVector2f limit_x = {(float)link->ground.left + link->quarter.x,
        (float)link->ground.left + (link->quarter.x * 3)};
    sfVector2f limit_y = {(float)link->ground.top + link->quarter.y,
        (float)link->ground.top + (link->quarter.y * 3)};

    for (int i = 0; i < 240; i += 1) {
        for (int j = 0; j < 135; j += 1) {
            if (check_collision_dir_2((int[2]){i, j},
            (sfVector2f[2]){limit_x, limit_y},
            (float[2]){disp1, disp2}, link) == 0)
                return (0);
        }
    }
    return (1);
}

int check_collision(scene_t *game_scene, link_t *link, int move, float disp)
{
    (void)game_scene;
    switch (move) {
        case 0: return (check_collision_dir(link, 0, -disp * 2));
        case 1: return (check_collision_dir(link, 0, disp * 2));
        case 2: return (check_collision_dir(link, -disp * 3, 0));
        case 3: return (check_collision_dir(link, disp * 2, 0));
        default: break;
    }
    return (1);
}