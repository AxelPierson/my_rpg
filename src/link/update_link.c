/*
** EPITECH PROJECT, 2019
** update
** File description:
** update
*/

#include "my_rpg.h"

void update_link(game_t *game)
{
    if (game->link->status == L_DEAD) {
        if (game->fade->state == 0 &&
            game->link->anim[game->link->previous_anim]->index == 4) {
            game->fade->state = 1;
            game->fade->index = 1080;
        }
        if (game->fade->state == 2) {
            game->link->previous_anim = 0;
            game->fade->state = 3;
            reset_link(game);
        }
    }
    update_walk(game->link, game->ui.arrow.drawable);
    game->link->pos.x = game->link->ground.left + game->link->quarter.x * 2;
    game->link->pos.y = game->link->ground.top + game->link->quarter.y * 2;
}