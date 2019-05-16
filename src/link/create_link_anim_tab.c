/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** create_link_anim_tab.c
*/

#include "animation.h"

anim_t *create_anim(sfVector2f coord, sfVector2f size, int nbr)
{
    (void)size;
    anim_t *new_anim = malloc(sizeof(anim_t));

    new_anim->coord = coord;
    new_anim->init_pos = coord.x;
    new_anim->size = (sfVector2f){51, 51};
    new_anim->index = 0;
    new_anim->nbr = nbr;
    return (new_anim);
}

anim_t **create_link_anim_tab(void)
{
    anim_t **anim_link = malloc(sizeof(anim_t) * 13);

    anim_link[0] = create_anim((sfVector2f){0, 0}, (sfVector2f){51, 51}, 7);
    anim_link[1] = create_anim((sfVector2f){0, 153}, (sfVector2f){51, 51}, 7);
    anim_link[2] = create_anim((sfVector2f){0, 51}, (sfVector2f){51, 51}, 7);
    anim_link[3] = create_anim((sfVector2f){0, 102}, (sfVector2f){51, 51}, 7);
    anim_link[4] = create_anim((sfVector2f){0, 204}, (sfVector2f){51, 51}, 6);
    anim_link[5] = create_anim((sfVector2f){0, 357}, (sfVector2f){51, 51}, 6);
    anim_link[6] = create_anim((sfVector2f){0, 255}, (sfVector2f){51, 51}, 6);
    anim_link[7] = create_anim((sfVector2f){0, 306}, (sfVector2f){51, 51}, 6);
    anim_link[8] = create_anim((sfVector2f){408, 0}, (sfVector2f){51, 51}, 5);
    anim_link[9] = create_anim((sfVector2f){408, 153}, (sfVector2f){51, 51},
    5);
    anim_link[10] = create_anim((sfVector2f){408, 51}, (sfVector2f){51, 51},
    5);
    anim_link[11] = create_anim((sfVector2f){408, 102},
        (sfVector2f){51, 51}, 5);
    anim_link[12] = create_anim((sfVector2f){408, 204},
        (sfVector2f){51, 51}, 14);
    return (anim_link);
}