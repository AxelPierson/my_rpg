/*
** EPITECH PROJECT, 2019
** item
** File description:
** item
*/

#include "my_rpg.h"

void get_bow(game_t *game)
{
    game->ui.item[1].status = true;
    sfSprite_setTexture(game->ui.item[1].spr, game->ui.texture[BOW], false);
    game->ui.arrow.drawable = true;
}

void get_lock(game_t *game)
{
    game->ui.item[2].status = true;
    sfSprite_setTexture(game->ui.item[2].spr, game->ui.texture[LOCK], false);
}