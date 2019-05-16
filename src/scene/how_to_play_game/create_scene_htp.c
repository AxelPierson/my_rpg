/*
** EPITECH PROJECT, 2019
** c
** File description:
** c
*/

#include "my_rpg.h"

scene_t create_scene_how_to_play(void)
{
    scene_t scene;

    scene.sprite = malloc(sizeof(sprite_t) * 3);
    scene.text = malloc(sizeof(text_t) * 10);
    init_sprite_htp(scene.sprite);
    init_text_htp(scene.text);
    return (scene);
}