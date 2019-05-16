/*
** EPITECH PROJECT, 2019
** how_to_play
** File description:
** how_to_play
*/

#include "my_rpg.h"

int event_htp(window_t * window, game_t *game)
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

void draw_back_htp(game_t *game, window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
        game->scene[S_GAME].sprite[0].sprite, NULL);
    draw_link(game->link, window, NULL);
    draw_ui(game, window);
    sfRenderWindow_drawRectangleShape(window->window,
        game->scene[S_PAUSE_GAME].rectangle[0].shape, NULL);
    draw_x_button(4, game->scene[S_PAUSE_GAME].button, window, 1);
    draw_x_text(4, game->scene[S_PAUSE_GAME].text, window);

}

int how_to_play(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int looping = true;

    while (looping == true) {
        sfRenderWindow_clear(window->window, sfBlack);
        looping = event_htp(window, game);
        draw_back_htp(game, window);
        sfRenderWindow_drawSprite(window->window,
            game->scene[S_HOWTOPLAY].sprite[0].sprite, NULL);
        sfRenderWindow_drawSprite(window->window,
            game->scene[S_HOWTOPLAY].sprite[1].sprite, NULL);
        sfRenderWindow_drawSprite(window->window,
            game->scene[S_HOWTOPLAY].sprite[2].sprite, NULL);
        draw_x_text(10, game->scene[S_HOWTOPLAY].text, window);
        sfRenderWindow_display(window->window);
    }
    return (true);
}