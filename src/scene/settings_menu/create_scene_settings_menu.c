/*
** EPITECH PROJECT, 2019
** c
** File description:
** c
*/

#include "my_rpg.h"

scene_t create_scene_settings(void)
{
    scene_t scene;

    scene.button = malloc(sizeof(button_t) *6);
    scene.sound = malloc(sizeof(sound_t) * 2);
    scene.text = malloc(sizeof(text_t) * 10);
    init_sound_settings(scene.sound);
    init_button_settings(scene.button, scene.sound);
    init_text_settings(scene.text);
    return (scene);
}