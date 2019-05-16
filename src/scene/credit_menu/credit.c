/*
** EPITECH PROJECT, 2019
** credit
** File description:
** credit
*/

#include "my_rpg.h"

void reset_credit(game_t *game)
{
    sfText_setPosition(game->scene[S_CREDIT].text[1].text,
        (sfVector2f){800, -400});
    sfText_setPosition(game->scene[S_CREDIT].text[2].text,
        (sfVector2f){800, -500});
    sfText_setPosition(game->scene[S_CREDIT].text[3].text,
        (sfVector2f){800, -600});
    sfText_setPosition(game->scene[S_CREDIT].text[4].text,
        (sfVector2f){800, -700});
    sfText_setPosition(game->scene[S_CREDIT].text[5].text,
        (sfVector2f){800, -100});
}

int event_credit(window_t *window, game_t *game)
{
    (void)game;
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased &&
            window->event.key.code == sfKeyEscape) {
            return (false);
            }
    }
    return (true);
}

int credit(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int looping = true;

    while (looping == true) {
        sfRenderWindow_clear(window->window, sfBlack);
        looping = event_credit(window, game);
        sfRenderWindow_drawRectangleShape(window->window,
        game->scene[S_CREDIT].rectangle[0].shape, NULL);
        sfText_move(game->scene[S_CREDIT].text[1].text, (sfVector2f){0, 1});
        sfText_move(game->scene[S_CREDIT].text[2].text, (sfVector2f){0, 1});
        sfText_move(game->scene[S_CREDIT].text[3].text, (sfVector2f){0, 1});
        sfText_move(game->scene[S_CREDIT].text[4].text, (sfVector2f){0, 1});
        sfText_move(game->scene[S_CREDIT].text[5].text, (sfVector2f){0, 1});
        draw_x_text(6, game->scene[S_CREDIT].text, window);
        sfRenderWindow_display(window->window);
    }
    reset_credit(game);
    return (true);
}