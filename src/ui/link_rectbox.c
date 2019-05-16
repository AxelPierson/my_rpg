/*
** EPITECH PROJECT, 2019
** rect
** File description:
** rect
*/

#include "my_rpg.h"

int link_rectbox(sfVector2f r_pos, sfVector2f r_size, link_t *l)
{
    if (l->pos.x * 4.3 > r_pos.x && l->pos.x * 4.3 < r_pos.x + r_size.x
        && l->pos.y * 4.3 > r_pos.y && l->pos.y * 4.3 < r_pos.y + r_size.y)
        return (true);
    return (false);
}