/*
** EPITECH PROJECT, 2019
** c
** File description:
** c
*/

#include "my_rpg.h"

scene_t create_scene_load_game(void)
{
    scene_t scene;

    scene.text = malloc(sizeof(text_t) * 2);
    init_text_load_game(scene.text);
    return (scene);
}