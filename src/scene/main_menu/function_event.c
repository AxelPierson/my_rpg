/*
** EPITECH PROJECT, 2019
** event
** File description:
** event
*/

#include "my_rpg.h"
#include "game.h"


int do_button_selected_main_menu(window_t *window, game_t *game,
    int *button_selected, int nb_button)
{
    int looping = true;

    if (window->event.key.code == sfKeyReturn) {
        for (int i = 0; i < nb_button; i++) {
            if (game->scene[S_MAIN_MENU].button[i].button_role ==
                *button_selected) {
                music_play_effect_if_activated(
                        game->scene[S_MAIN_MENU].sound[2]);
                looping = game->scene[S_MAIN_MENU].button[i].callback(
                        game, window, NULL);
                return (looping);
            }
        }
    }
    return (true);
}

int event_main_menu(window_t *window, game_t *game, int *button_selected)
{
    int looping = true;

    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased) {
            update_button_selected(window->event, button_selected,
                (int[3]){NEW_PARTY, QUIT, 5}, &game->scene[S_MAIN_MENU]);
            looping = do_button_selected_main_menu(
                window, game, button_selected, 5);
        }
    }
    return (looping);
}