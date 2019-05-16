/*
** EPITECH PROJECT, 2019
** e
** File description:
** e
*/

#include "my_rpg.h"

int effect_vol_d(game_t *game, window_t *window, void *extra)
{
    (void)window;
    (void)extra;

    if (effect_vol > 0) {
        effect_vol -= 10;
        notification_settings = true;
    }
    music_play_effect_if_activated(game->scene[S_SETTINGS_MENU].sound[1]);
    return (true);
}

int effect_vol_u(game_t *game, window_t *window, void *extra)
{
    (void)window;
    (void)extra;

    if (effect_vol < 100) {
        effect_vol += 10;
        notification_settings = true;
    }
    music_play_effect_if_activated(game->scene[S_SETTINGS_MENU].sound[1]);
    return (true);
}

int effect_music_d(game_t *game, window_t *window, void *extra)
{
    (void)window;
    (void)extra;

    if (music_vol > 0) {
        music_vol -= 10;
        notification_settings = true;
    }
    music_play_effect_if_activated(game->scene[S_SETTINGS_MENU].sound[1]);
    return (true);
}

int effect_music_u(game_t *game, window_t *window, void *extra)
{
    (void)window;
    (void)extra;

    if (music_vol < 100) {
        music_vol += 10;
        notification_settings = true;
    }
    music_play_effect_if_activated(game->scene[S_SETTINGS_MENU].sound[1]);
    return (true);
}