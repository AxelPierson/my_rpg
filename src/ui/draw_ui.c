/*
** EPITECH PROJECT, 2019
** ui
** File description:
** ui
*/

#include "my_rpg.h"

void draw_map(game_t *game, window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    game->scene[S_GAME].sprite[0].sprite, NULL);
}

void draw_icon(game_t *game, window_t *window, int index)
{
    sfRenderWindow_drawSprite(window->window,
        game->ui.icon[index].sprite, NULL);
}

void draw_ui(game_t *game, window_t *window)
{
    sfRenderWindow_drawSprite(window->window, game->ui.life.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game->ui.heart[0].spr, NULL);
    sfRenderWindow_drawSprite(window->window, game->ui.heart[1].spr, NULL);
    sfRenderWindow_drawSprite(window->window, game->ui.heart[2].spr, NULL);
    sfRenderWindow_drawSprite(window->window, game->ui.item[0].spr, NULL);
    sfRenderWindow_drawSprite(window->window, game->ui.item[1].spr, NULL);
    icon_sign(game, window);
    if (game->ui.arrow.drawable == true)
            sfRenderWindow_drawText(window->window,
                game->ui.arrow.text, NULL);
}