/*
** EPITECH PROJECT, 2019
** life
** File description:
** life
*/

#include "my_rpg.h"

void increase_life(game_t *game)
{
    sfIntRect rect = {0, 0, 0, 0};

    for (int i = 2; i >= 0; i--) {
        if (game->ui.heart[i].status != H_FULL) {
            game->ui.heart[i].status += 1;
            rect = sfSprite_getTextureRect(game->ui.heart[i].spr);
            rect.left -= 43;
            sfSprite_setTextureRect(game->ui.heart[i].spr, rect);
            game->link->status = L_ALIVE;
            return;
        }
    }
}

void decrease_life(game_t *game)
{
    sfIntRect rect = {0, 0, 0, 0};

    for (int i = 0; i < 3; i++) {
        if (game->ui.heart[i].status != H_EMPTY) {
            game->ui.heart[i].status -= 1;
            rect = sfSprite_getTextureRect(game->ui.heart[i].spr);
            rect.left += 43;
            sfSprite_setTextureRect(game->ui.heart[i].spr, rect);
            game->link->status = L_ALIVE;
            if (i == 2 && game->ui.heart[i].status == H_EMPTY)
                game->link->status = L_DEAD;
            return;
        }
    }
}