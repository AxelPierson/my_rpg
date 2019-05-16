/*
** EPITECH PROJECT, 2019
** update
** File description:
** update
*/

#include "my_rpg.h"

void update_regen(game_t *game)
{
    float time = sfClock_getElapsedTime(game->ui.regen
        ).microseconds / (1000000.0);

    if (time > 15) {
        increase_life(game);
        sfClock_restart(game->ui.regen);
    }
}

void update_ui(game_t *game)
{
    update_regen(game);
    switch (game->link->status) {
        case L_DAMAGE: decrease_life(game);
            break;
        case L_HEAL: increase_life(game);
            break;
        default: break;
    }
    update_sign(game);
}