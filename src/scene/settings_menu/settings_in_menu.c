/*
** EPITECH PROJECT, 2019
** settings
** File description:
** settings
*/

#include "my_rpg.h"

int do_button_selected_settings(window_t *window, game_t *game,
    int *button_selected, int nb_button)
{
    int looping = true;

    for (int i = 0; i < nb_button; i++) {
        if (game->scene[S_SETTINGS_MENU].button[i].button_role
            == *button_selected) {
            music_play_effect_if_activated(
                game->scene[S_SETTINGS_MENU].sound[1]);
            looping = game->scene[S_SETTINGS_MENU].button[i].callback(
                game, window, NULL);
            return (looping);
            }
        }
    return (looping);
}

int event_settings(window_t *window, game_t *game, int *button_selected)
{
    int looping = true;

    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased) {
            if (window->event.key.code == sfKeyEscape)
                looping = false;
            if (window->event.key.code == sfKeyReturn)
                do_button_selected_settings(window, game, button_selected, 6);
            update_button_selected(window->event, button_selected, (int[3]){
                VOL_EFFECT_D, VOL_OFF, 6}, &game->scene[S_SETTINGS_MENU]);
        }
    }
    return (looping);
}

void pool_music(scene_t *scene, scene_t *settings)
{
    if (notification_settings == true)
        notification_settings = false;
    else
        return ;
    music_update(settings->sound, 2);
    music_update(scene->sound, 2);
}

int settings_in_menu(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int looping = true;
    int button_selected = VOL_EFFECT_D;

    while (looping == true) {
        sfRenderWindow_clear(window->window, sfBlack);
        looping = event_settings(window, game, &button_selected);
        pool_music(&game->scene[S_MAIN_MENU],
            &game->scene[S_SETTINGS_MENU]);
        draw_parallax_menu(window, &game->scene[S_MAIN_MENU]);
        draw_x_button(6, game->scene[S_SETTINGS_MENU].
            button, window, button_selected);
        draw_x_text(10, game->scene[S_SETTINGS_MENU].text, window);
        sfRenderWindow_display(window->window);
    }
    return (true);
}