/*
** EPITECH PROJECT, 2019
** pause
** File description:
** pause
*/

#include "my_rpg.h"
#include "link.h"

int do_button_selected_pause(window_t *window, game_t *game,
    int *button_selected, int nb_button)
{
    int looping = true;

    for (int i = 0; i < nb_button; i++) {
        if (game->scene[S_PAUSE_GAME].button[i].button_role
            == *button_selected) {
            music_play_effect_if_activated(
                game->scene[S_PAUSE_GAME].sound[1]);
            looping = game->scene[S_PAUSE_GAME].button[i].callback(
                game, window, NULL);
            return (looping);
            }
        }
    return (looping);
}

int event_pause(window_t * window, game_t *game, int *button_selected)
{
    int looping = true;

    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased &&
            window->event.key.code == sfKeyEscape)
            looping = false;
        if (window->event.type == sfEvtKeyReleased &&
            window->event.key.code == sfKeyReturn)
            looping = do_button_selected_pause(window,
                game, button_selected, 4);
        if (window->event.type == sfEvtKeyReleased) {
            update_button_selected(window->event, button_selected, (int[3]){
                RESUME, BACK_TO_MENU, 4}, &game->scene[S_PAUSE_GAME]);
        }
    }
    return (looping);
}

void draw_back_pg(game_t *game, window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
        game->scene[S_GAME].sprite[0].sprite, NULL);
    draw_link(game->link, window, NULL);
    draw_ui(game, window);
}

int pause_game(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int button_selected = RESUME;
    int looping = true;

    while (looping == true) {
        music_update(game->scene[S_PAUSE_GAME].sound, 2);
        sfRenderWindow_clear(window->window, sfBlack);
        looping = event_pause(window, game, &button_selected);
        draw_back_pg(game, window);
        sfRenderWindow_drawRectangleShape(window->window,
            game->scene[S_PAUSE_GAME].rectangle[0].shape, NULL);
        draw_x_button(4, game->scene[S_PAUSE_GAME].button,
            window, button_selected);
        draw_x_text(4, game->scene[S_PAUSE_GAME].text, window);
        sfRenderWindow_display(window->window);
    }
    if (looping == BACK_TO_MENU)
        return (BACK_TO_MENU);
    return (true);
}