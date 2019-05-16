/*
** EPITECH PROJECT, 2019
** calc_dist_dir.h
** File description:
** calc_dist_dir.h
*/

#ifndef CALC_DIST_DIR_H_
#define CALC_DIST_DIR_H_

#include "lib.h"
#include "sprite.h"

float calc_dist(sfVector2f pos1, sfVector2f dim1, sfVector2f pos2,
    sfVector2f dim2);
sfVector2f calc_dir(sfVector2f pos1, sfVector2f pos2, sfVector2f *dim,
    float distance);

#endif /* !CALC_DIST_DIR_H_ */