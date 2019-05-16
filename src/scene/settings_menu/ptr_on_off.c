/*
** EPITECH PROJECT, 2019
** ptr
** File description:
** ptr
*/

#include "my_rpg.h"

int vol_off(game_t *game, window_t *window, void *extra)
{
    (void)window;
    (void)extra;

    sound_activated = false;
    notification_settings = true;
    music_play_effect_if_activated(game->scene[S_SETTINGS_MENU].sound[1]);
    return (true);
}

int vol_on(game_t *game, window_t *window, void *extra)
{
    (void)window;
    (void)extra;

    sound_activated = true;
    notification_settings = true;
    music_play_effect_if_activated(game->scene[S_SETTINGS_MENU].sound[1]);
    return (true);
}