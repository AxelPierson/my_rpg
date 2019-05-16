/*
** EPITECH PROJECT, 2019
** s
** File description:
** s
*/

#include "my_rpg.h"

scene_t create_scene_credit(void)
{
    scene_t scene;

    scene.rectangle = malloc(sizeof(rectangle_t) * 1);
    scene.text = malloc(sizeof(text_t) * 6);
    init_rectangle_credit(scene.rectangle);
    init_text_credit(scene.text);
    return (scene);
}