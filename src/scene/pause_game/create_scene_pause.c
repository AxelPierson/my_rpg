/*
** EPITECH PROJECT, 2019
** c
** File description:
** c
*/

#include "my_rpg.h"

scene_t create_scene_pause(void)
{
    scene_t scene;

    scene.rectangle = malloc(sizeof(rectangle_t) * 1);
    scene.button = malloc(sizeof(button_t) * 4);
    scene.sound = malloc(sizeof(sound_t) * 2);
    scene.text = malloc(sizeof(text_t) * 4);
    init_sound_pause(scene.sound);
    init_rectangle_pause(scene.rectangle);
    init_button_pause(scene.button, scene.sound);
    init_text_pause(scene.text);
    return (scene);
}