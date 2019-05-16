/*
** EPITECH PROJECT, 2019
** reset
** File description:
** reset
*/

#include "my_rpg.h"

void reset_item(game_t *game)
{
    game->ui.item[1].status = false;
    game->ui.item[2].status = false;
    sfSprite_setTexture(game->ui.item[1].spr, game->ui.texture[EMPTY], false);
    sfSprite_setTexture(game->ui.item[2].spr, game->ui.texture[EMPTY], false);
    game->ui.arrow.drawable = false;
}

void reset_link(game_t *game)
{
    sfVector2f pos = (sfVector2f){0, 0};
    sfIntRect rect = {0, 0, 43, 43};

    game->link->status = L_ALIVE;
    for (int i = 0; i < 3; i++) {
        game->ui.heart[i].status = H_FULL;
        sfSprite_setTextureRect(game->ui.heart[i].spr, rect);
    }
    pos = game->sign[game->checkpoint].position;
    spawn_pos.top = (pos.y / 4.3) - 100;
    spawn_pos.left = (pos.x / 4.3) - 215;
    sfSprite_setTextureRect(game->scene[S_GAME].sprite[0].sprite, spawn_pos);
    game->link->ground = spawn_pos;
    game->link->pos.x = game->link->ground.left + game->link->quarter.x * 2;
    game->link->pos.y = game->link->ground.top + game->link->quarter.y * 2;
}

void reset_function(game_t *game)
{
    reset_link(game);
    reset_arrow(game);
    reset_item(game);
}