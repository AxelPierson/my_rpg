/*
** EPITECH PROJECT, 2019
** reset
** File description:
** reset
*/

#include "my_rpg.h"

void reset_spawn_value(game_t *game, sfIntRect rect_spawn)
{
    sfIntRect rect_heart = {0, 0, 43, 43};

    sfSprite_setTextureRect(game->scene[S_GAME].sprite[0].sprite, rect_spawn);
    game->link->ground = rect_spawn;
    for (int i = 0; i < 3; i++) {
        game->ui.heart[i].status = H_FULL;
        sfSprite_setTextureRect(game->ui.heart[i].spr, rect_heart);
    }
    game->link->status = L_ALIVE;
    sfSprite_setTexture(game->ui.item[1].spr, game->ui.texture[EMPTY], false);
    sfSprite_setTexture(game->ui.item[2].spr, game->ui.texture[EMPTY], false);
}