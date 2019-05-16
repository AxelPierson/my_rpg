/*
** EPITECH PROJECT, 2019
** apply
** File description:
** apply
*/

#include "my_rpg.h"

void apply_checkpoint(game_t *game)
{
    for (int i = 0; i < 6; i += 1) {
        if (link_rectbox(game->sign[i].position,
            game->sign[i].size, game->link) == true) {
            game->checkpoint = i;
        }
    }
}