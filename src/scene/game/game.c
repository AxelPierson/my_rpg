/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my_rpg.h"
#include "zone.h"
#include "npc.h"
#include "globals.h"

void update_game(game_t *game, window_t *window, scene_t *scene)
{
    (void)window;
    DT = sfClock_getElapsedTime(delta_clock).microseconds /
        (1000000.0 / 60.0);
    main_time = sfClock_getElapsedTime(main_clock).microseconds /
        1000000.0 + 11;
    update_zone(game->zones, game->link);
    sfClock_restart(delta_clock);
    update_view(game, &scene[S_GAME], game->link, DT);
    update_link(game);
    update_arrow(game->link);
    update_monst_list(game->link->ground, game->zones, game->link);
    update_ui(game);
    update_music(game->music, game->link->pos);
}

int event_released(window_t *window, game_t *game)
{
    int looping = true;

    if (window->event.key.code == sfKeyEscape)
        looping = pause_game(game, window, NULL);
    if (window->event.key.code == sfKeyE &&
        game->ui.icon[I_HEAD].status == true) {
        apply_checkpoint(game);
        write_save(game);
    }
    if (window->event.key.code == sfKeyE)
        game->link->event = 2;
    if (window->event.key.code == sfKeyD)
        game->link->event = 1;
    if (window->event.key.code == sfKeyQ)
        update_arrow_counter(game);
    return (looping);
}

int event_game(window_t *window, game_t *game)
{
    int looping = true;

    if (end_game(game, window) == false)
        return (false);
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased)
            looping = event_released(window, game);
    }
    return (looping);
}

void play_game(game_t *game, window_t *window)
{
    int looping = true;

    update_ef_vol(game);
    sfMusic_stop(game->scene[S_MAIN_MENU].sound[0].music);
    game->scene[S_MAIN_MENU].sound[0].is_sound = false;
    notification_settings = true;
    while (looping == true) {
        looping = event_game(window, game);
        update_game(game, window, game->scene);
        draw_map(game, window);
        update_npc(game, game->pop, window->window);
        check_current_zone(window, game->zones);
        draw_link(game->link, window, NULL);
        draw_ui(game, window);
        update_textbox(game->box, window->window, &game->link->event);
        use_fade(game->fade, window);
        sfRenderWindow_display(window->window);
    }
    reset_function(game);
}