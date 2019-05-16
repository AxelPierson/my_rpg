/*
** EPITECH PROJECT, 2019
** effect
** File description:
** effect
*/

#include "my_rpg.h"
#include "globals.h"

void update_ef_vol(game_t *game)
{
    for (int i = 0; i < size_snd; i++) {
        sfSound_setVolume(game->link->snd[i], effect_vol);
    }
}