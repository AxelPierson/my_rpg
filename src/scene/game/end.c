/*
** EPITECH PROJECT, 2019
** end
** File description:
** end
*/

#include "my_rpg.h"
#include "zone.h"
#include "npc.h"
#include "globals.h"

int event_end(game_t *game, window_t *window)
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

void loop_end(game_t *game, window_t *window)
{
    int looping = true;

    sfMusic_stop(game->music->snd[game->music->actual]);
    sfSound_play(game->link->snd[5]);
    while (looping == true) {
        looping = event_end(game, window);
        draw_map(game, window);
        check_current_zone(window, game->zones);
        draw_link(game->link, window, NULL);
        draw_ui(game, window);
        sfRenderWindow_drawSprite(window->window, game->scene[S_GAME].
            sprite[1].sprite, NULL);
        sfRenderWindow_drawRectangleShape(window->window, game->scene
            [S_GAME].rectangle[0].shape, NULL);
        sfRenderWindow_drawText(window->window, game->
            scene[S_CREDIT].text[0].text, NULL);
        sfRenderWindow_display(window->window);
        }
}

int end_game(game_t *game, window_t *window)
{
    if (end == false)
        return (true);
    else {
        loop_end(game, window);
        sfSound_stop(game->link->snd[5]);
    }
    return (false);
}