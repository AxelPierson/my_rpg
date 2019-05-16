/*
** EPITECH PROJECT, 2019
** arrow
** File description:
** arrow
*/

#include "my_rpg.h"

void increase_arrow(game_t *game)
{
    if (game->ui.arrow.n == 20 || game->ui.arrow.drawable == false)
        return;
    else
        game->ui.arrow.n += 1;
}

void decrease_arrow(game_t *game)
{
    if (game->ui.arrow.n == 0 || game->ui.arrow.drawable == false)
        return;
    else
        game->ui.arrow.n -= 1;
}

void update_arrow_counter(game_t *game)
{
    sfText_setString(game->ui.arrow.text, int_char(game->link->arrow->nbr));
}

void reset_arrow(game_t *game)
{
    game->ui.arrow.n = 20;
    sfText_setString(game->ui.arrow.text, int_char(game->ui.arrow.n));
}