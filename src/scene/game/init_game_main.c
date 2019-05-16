/*
** EPITECH PROJECT, 2019
** o
** File description:
** i
*/

#include "my_rpg.h"
#include "game.h"
#include "globals.h"
#include "fade.h"
#include "zone.h"
#include "npc.h"

void init_scene_game(game_t *game)
{
    game->scene[S_MAIN_MENU] = create_scene_main_menu();
    game->scene[S_GAME] = create_scene_game();
    game->scene[S_LOAD_GAME] = create_scene_load_game();
    game->scene[S_SETTINGS_MENU] = create_scene_settings();
    game->scene[S_CREDIT] = create_scene_credit();
    game->scene[S_PAUSE_GAME] = create_scene_pause();
    game->scene[S_SETTINGS_PAUSE] = create_scene_settings_pause();
    game->scene[S_HOWTOPLAY] = create_scene_how_to_play();
}

int init_globals(void)
{
    sound_activated = true;
    notification_settings = false;
    effect_vol = 50;
    music_vol = 50;
    size_snd = 4;
    spawn_pos = (sfIntRect){575, 1611, 1920, 1080};
    map_test = malloc(sizeof(int *) * 135);
    if (fill_map() == 84)
        return (84);
    end = false;
    delta_clock = sfClock_create();
    main_clock = sfClock_create();
    return (0);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->scene = malloc(sizeof(scene_t) * 8);
    game->sign = malloc(sizeof(checkpoint_t) * 6);
    init_scene_game(game);
    init_ui(game);
    init_checkpoint(game);
    game->pop = create_people(game);
    game->pop = create_people(game);
    game->end = false;
    game->box = create_textbox();
    game->fade = create_fade();
    game->link = NULL;
    game->music = init_music();
    game->checkpoint = 0;
    game->zones = create_zone_list(4);
    return (game);
}