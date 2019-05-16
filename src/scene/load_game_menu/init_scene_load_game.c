/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"

void init_text_load_game(text_t *element)
{
    element[0] = create_text("assets/font.ttf", "Press escape to leave",
        (sfVector2f){1500, 1030}, (sfVector2f){0.5, 0.5});
    element[1] = create_text("assets/font.ttf", "NO SAVES FOUND",
        (sfVector2f){554, 400}, (sfVector2f){1, 1});
}