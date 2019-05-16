/*
** EPITECH PROJECT, 2019
** p
** File description:
** o
*/

#include "my_rpg.h"

void played_sound_button_selected(int *index, button_t *button, int nb_button)
{
    if (is_sound_activated() == true) {
        for (int i = 0; i < nb_button; i++) {
            if (button[i].button_role == *index)
                sfMusic_play(button[i].sound);
        }
    }
}