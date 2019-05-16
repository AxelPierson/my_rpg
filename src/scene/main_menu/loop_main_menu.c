/*
** EPITECH PROJECT, 2019
** loop
** File description:
** loop
*/

#include "my_rpg.h"
#include "game.h"
#include "globals.h"

scene_t create_scene_main_menu(void)
{
    scene_t scene;

    scene.sprite = malloc(sizeof(sprite_t) * 1);
    scene.button = malloc (sizeof(button_t) * 5);
    scene.text = malloc(sizeof(text_t) * 5);
    scene.sound = malloc(sizeof(sound_t) * 3);
    init_text_main_menu(scene.text);
    init_sound_main_menu(scene.sound);
    init_button_main_menu(scene.button, scene.sound);
    init_sprite_main_menu(scene.sprite);
    return (scene);
}

void draw_parallax_menu(window_t *window, scene_t *scene)
{
    sfVector2f position = sfSprite_getPosition(scene->sprite[0].sprite);

    if (position.y <= 0)
        sfSprite_move(scene->sprite[0].sprite, (sfVector2f){0, 1.5});
    else
        sfSprite_setPosition(scene->sprite[0].sprite, (sfVector2f){-6336,
        - 4678});
    sfRenderWindow_drawSprite(window->window, scene->sprite[0].sprite, NULL);
}

void inside_loop(window_t *window, game_t *game,
    int *looping, int *button_selected)
{
    if (game->music->actual != -1) {
            sfMusic_stop(game->music->snd[game->music->actual]);
            game->music->actual = -1;
    }
        sfRenderWindow_clear(window->window, sfBlack);
        music_update(game->scene[S_MAIN_MENU].sound, 3);
        *looping = event_main_menu(window, game, button_selected);
        draw_parallax_menu(window, &game->scene[S_MAIN_MENU]);
        draw_x_button(5, game->scene[S_MAIN_MENU].button, window, \
        *button_selected);
        draw_x_text(5, game->scene[S_MAIN_MENU].text, window);
        end = false;
        sfRenderWindow_display(window->window);
}

int loop_main_menu(window_t *window, game_t *game)
{
    int button_selected = NEW_PARTY;
    int looping = true;

    sfMusic_play(game->scene[S_MAIN_MENU].sound[0].music);
    game->scene[S_MAIN_MENU].sound[0].is_sound = true;
    while (looping == true) {
        inside_loop(window, game, &looping, &button_selected);
    }
    return (QUIT);
}