/*
** EPITECH PROJECT, 2019
** draw
** File description:
** draw
*/

#include "my_rpg.h"

void draw_x_text(int nb_text, text_t *text, window_t *window)
{
    for (int i = 0; i < nb_text; i++)
        sfRenderWindow_drawText(window->window, text[i].text, NULL);
}