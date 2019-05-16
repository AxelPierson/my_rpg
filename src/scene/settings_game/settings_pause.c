/*
** EPITECH PROJECT, 2019
** settings
** File description:
** settings
*/

#include "my_rpg.h"


int do_button_selected_settings_pause(window_t *window, game_t *game,
    int *button_selected, int nb_button)
{
    int looping = true;

    for (int i = 0; i < nb_button; i++) {
        if (game->scene[S_SETTINGS_PAUSE].button[i].button_role
            == *button_selected) {
            music_play_effect_if_activated(game->scene[S_SETTINGS_PAUSE].
            sound[1]);
            looping = game->scene[S_SETTINGS_PAUSE].button[i].callback(
                game,  window, NULL);
            return (looping);
            }
        }
    return (true);
}

int event_settings_pause(window_t *window, game_t *game, int *button_selected)
{
    int looping = true;

    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased &&
            window->event.key.code == sfKeyEscape)
            looping = false;
        if (window->event.type == sfEvtKeyReleased &&
            window->event.key.code == sfKeyReturn)
            do_button_selected_settings_pause(window,
                game, button_selected, 6);
        if (window->event.type == sfEvtKeyReleased) {
            update_button_selected(window->event, button_selected, (int[3]){
                VOL_EFFECT_D, VOL_OFF, 6}, &game->scene[S_SETTINGS_PAUSE]);
        }
    }
    return (looping);
}

void draw_back_sp(game_t *game, window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
        game->scene[S_GAME].sprite[0].sprite, NULL);
    draw_link(game->link, window, NULL);
    draw_ui(game, window);
    sfRenderWindow_drawRectangleShape(window->window,
        game->scene[S_PAUSE_GAME].rectangle[0].shape, NULL);
    draw_x_button(4, game->scene[S_PAUSE_GAME].button, window, 2);
    draw_x_text(4, game->scene[S_PAUSE_GAME].text, window);
}

int settings_pause(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int looping = true;
    int button_selected = VOL_EFFECT_D;

    while (looping == true) {
        music_update(game->scene[S_SETTINGS_PAUSE].sound, 2);
        music_update(game->scene[S_SETTINGS_MENU].sound, 2);
        update_music(game->music, game->link->pos);
        sfRenderWindow_clear(window->window, sfBlack);
        looping = event_settings_pause(window, game, &button_selected);
        pool_music(&game->scene[S_GAME], &game->scene[S_SETTINGS_PAUSE]);
        draw_back_sp(game, window);
        draw_x_button(6,
            game->scene[S_SETTINGS_PAUSE].button, window, button_selected);
        draw_x_text(10, game->scene[S_SETTINGS_PAUSE].text, window);
        sfRenderWindow_display(window->window);
    }
    update_ef_vol(game);
    return (true);
}