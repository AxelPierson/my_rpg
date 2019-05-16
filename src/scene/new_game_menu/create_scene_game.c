/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my_rpg.h"

scene_t create_scene_game(void)
{
    scene_t scene;

    scene.sprite = malloc(sizeof(sprite_t) * 2);
    scene.button = malloc(sizeof(button_t) *2 );
    scene.sound = malloc(sizeof(sound_t) * 2);
    scene.text = malloc(sizeof(text_t) * 3);
    scene.rectangle = malloc(sizeof(rectangle_t) * 1);
    init_sprite_game(scene.sprite);
    init_sound_game(scene.sound);
    init_button_game(scene.button, scene.sound);
    init_text_game(scene.text);
    scene.rectangle[0] = create_rectangle((sfVector2f){1920, 1080},
        (sfVector2f){0, 0}, (sfColor){204, 255, 179, 50});
    return (scene);
}