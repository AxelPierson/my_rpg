/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** check_distance.c
*/

#include "link.h"
#include "my_rpg.h"

int rect_point(sfVector2f *tab, float *pos)
{
    if (pos[0] >= tab[0].x && pos[0] <= tab[0].x + tab[1].x
        && pos[1] >= tab[0].y && pos[1] <= tab[0].y + tab[1].y)
        return (1);
    return (0);
}

int pos1_into_pos2(sfVector2f obj_pos, sfVector2f dim_obj, \
sfVector2f obj_pos_2, sfVector2f dim_obj_2)
{
    int count = 0;

    count += rect_point((sfVector2f[2]){obj_pos, dim_obj}, \
    (float[2]){obj_pos_2.x, obj_pos_2.y});
    count += rect_point((sfVector2f[2]){obj_pos, dim_obj}, \
    (float[2]){obj_pos_2.x + dim_obj_2.x, obj_pos_2.y});
    count += rect_point((sfVector2f[2]){obj_pos, dim_obj}, \
    (float[2]){obj_pos_2.x + dim_obj_2.x, obj_pos_2.y + dim_obj_2.y});
    count += rect_point((sfVector2f[2]){obj_pos, dim_obj}, \
    (float[2]){obj_pos_2.x, obj_pos_2.y + dim_obj_2.y});
    return (count);
}

int pos2_into_pos1(sfVector2f obj_pos, sfVector2f dim_obj, \
sfVector2f obj_pos_2, sfVector2f dim_obj_2)
{
    int count = 0;

    count += rect_point((sfVector2f[2]){obj_pos_2, dim_obj_2}, \
    (float[2]){obj_pos.x, obj_pos.y});
    count += rect_point((sfVector2f[2]){obj_pos_2, dim_obj_2}, \
    (float[2]){obj_pos.x + dim_obj.x, obj_pos.y});
    count += rect_point((sfVector2f[2]){obj_pos_2, dim_obj_2}, \
    (float[2]){obj_pos.x + dim_obj.x, obj_pos.y + dim_obj.y});
    count += rect_point((sfVector2f[2]){obj_pos_2, dim_obj_2}, \
    (float[2]){obj_pos.x, obj_pos.y + dim_obj.y});
    return (count);
}

int hit_obstacle(sfVector2f obj_pos, sfVector2f dim_obj, \
sfVector2f obj_pos_2, sfVector2f dim_obj_2)
{
    int count = 0;

    count += pos1_into_pos2(obj_pos, dim_obj, obj_pos_2, dim_obj_2);
    count += pos2_into_pos1(obj_pos, dim_obj, obj_pos_2, dim_obj_2);
    if (count > 0)
        return (1);
    return (0);
}

int collide(sfVector2f new_obj_pos_2, sfVector2f obstacle_pos)
{
    if (hit_obstacle(obstacle_pos, (sfVector2f){16.0, 16.0}, \
    new_obj_pos_2, (sfVector2f){4.0, 9.0}) == 1) {
        return (1);
    }
    return (0);
}