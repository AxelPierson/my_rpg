/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"

void init_tex(sfTexture **tex)
{
    tex[EMPTY] = sfTexture_createFromFile("assets/logo.png", NULL);
    tex[SWORD] = sfTexture_createFromFile("assets/sword.png", NULL);
    tex[BOW] = sfTexture_createFromFile("assets/bow.png", NULL);
    tex[LOCK] = sfTexture_createFromFile("assets/lock.png", NULL);
}

sfVector2f set_icon(sfVector2f i_size)
{
    sfVector2f pos = (sfVector2f){0, 0};

    pos.x = 960 - i_size.x / 2;
    pos.y = 540 - i_size.y / 2;
    pos.x += (16 * 2.5);
    pos.y -= (24 * 2.5);
    return (pos);
}