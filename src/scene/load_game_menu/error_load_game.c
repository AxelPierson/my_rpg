/*
** EPITECH PROJECT, 2019
** e
** File description:
** e
*/

#include "my_rpg.h"

int event_load_game(window_t *window, game_t *game)
{
    (void)game;
    int looping = true;

    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased &&
            window->event.key.code == sfKeyEscape) {
            looping = false;
            }
    }
    return (looping);
}

void error_load_game(game_t *game, window_t *window)
{
    int looping = true;

    while (looping == true) {
        sfRenderWindow_clear(window->window, sfBlack);
        looping = event_load_game(window, game);
        draw_parallax_menu(window, &game->scene[S_MAIN_MENU]);
        sfRenderWindow_drawText(window->window,
            game->scene[S_LOAD_GAME].text[0].text, NULL);
        sfRenderWindow_drawText(window->window,
            game->scene[S_LOAD_GAME].text[1].text, NULL);
        sfRenderWindow_display(window->window);
    }
}