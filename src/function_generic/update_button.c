/*
** EPITECH PROJECT, 2019
** b
** File description:
** b
*/

#include "my_rpg.h"

int go_up(int *index, int *info, scene_t *scene)
{
    if (*index == info[0]) {
        *index = info[1];
        played_sound_button_selected(index, scene->button, info[2]);
        return (false);
    } else {
        *index -= 1;
        played_sound_button_selected(index, scene->button, info[2]);
        return (false);
    }
    return (true);
}

void update_button_selected(sfEvent event, int *index, int *info,
    scene_t *scene)
{
    if (event.key.code == sfKeyUp) {
        if (go_up(index, info, scene) == false)
            return;
    }
    if (event.key.code == sfKeyDown) {
        if (*index == info[1]) {
            *index = info[0];
            played_sound_button_selected(index, scene->button, info[2]);
            return;
        } else {
            *index += 1;
            played_sound_button_selected(index, scene->button, info[2]);
            return;
        }
    }
}