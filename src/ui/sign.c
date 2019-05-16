/*
** EPITECH PROJECT, 2019
** sign
** File description:
** sign
*/

#include "my_rpg.h"

void set_sign(checkpoint_t sign, sfIntRect ground)
{
    sfRectangleShape_setPosition(sign.shape, (sfVector2f){sign.position.x -
        ground.left * 4.3, sign.position.y - ground.top * 4.3});
}

void update_sign(game_t *game)
{
    for (int i = 0; i < 6; i++) {
        set_sign(game->sign[i], game->link->ground);
    }
}

void icon_sign(game_t *game, window_t *window)
{
    int index = false;

    for (int i = 0; i < 6; i++) {
        if (link_rectbox(game->sign[i].position,
            game->sign[i].size, game->link) == true) {
            game->ui.icon[I_HEAD].status = true;
            draw_icon(game, window, I_HEAD);
            index = true;
        }
    }
    if (index == false)
    game->ui.icon[I_HEAD].status = false;
}