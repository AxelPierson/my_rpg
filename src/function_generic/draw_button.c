/*
** EPITECH PROJECT, 2019
** drw
** File description:
** draw
*/

#include "my_rpg.h"

void draw_button(button_t button, window_t *window, int index)
{
    if (button.button_role == index)
        sfRenderWindow_drawSprite(window->window, button.sprite1, NULL);
    else
        sfRenderWindow_drawSprite(window->window, button.sprite0, NULL);
}

void draw_x_button(int nb_button, button_t *button, window_t *window,
int button_selected)
{
    for (int i = 0; i < nb_button; i++)
        draw_button(button[i], window, button_selected);
}