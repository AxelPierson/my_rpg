/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"

void init_rectangle_credit(rectangle_t *element)
{
    element[0] = create_rectangle((sfVector2f){1920, 1080},
        (sfVector2f){0, 0}, (sfColor){0, 0, 0, 255});
}

void init_text_credit(text_t *element)
{
    element[0] = create_text("assets/font.ttf", "Press escape to leave",
        (sfVector2f){1500, 1030}, (sfVector2f){0.5, 0.5});
    element[1] = create_text("assets/font.ttf", "Noe, math_killer.",
        (sfVector2f){800, -400}, (sfVector2f){1, 1});
    element[2] = create_text("assets/font.ttf", "Arnaud, menu_slayer.",
        (sfVector2f){800, -500}, (sfVector2f){1, 1});
    element[3] = create_text("assets/font.ttf", "Honorin, NPC_specialist.",
        (sfVector2f){800, -600}, (sfVector2f){1, 1});
    element[4] = create_text("assets/font.ttf", "Axel, Alex.",
        (sfVector2f){800, -700}, (sfVector2f){1, 1});
    element[5] = create_text("assets/font.ttf", "My_RPG Epitech",
        (sfVector2f){800, -100}, (sfVector2f){1, 1});
}