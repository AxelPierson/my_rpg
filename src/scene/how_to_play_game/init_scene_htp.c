/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"

void init_sprite_htp(sprite_t *element)
{
    element[0] = create_sprite("assets/HTP.png",
        (sfVector2f){835, 355}, (sfVector2f){380, 540});
    element[1] = create_sprite("assets/i_head.png",
        (sfVector2f){1387, 433}, (sfVector2f){380, 540});
    element[2] = create_sprite("assets/i_chat.png",
        (sfVector2f){1387, 533}, (sfVector2f){380, 540});
}

void init_text_htp(text_t *element)
{
    element[0] = create_text("assets/font.ttf", "Press escape to leave",
        (sfVector2f){1500, 1030}, (sfVector2f){0.5, 0.5});
    element[1] = create_text("assets/font.ttf", "Key UP : Go",
        (sfVector2f){869, 400}, (sfVector2f){0.8, 0.8});
    element[2] = create_text("assets/font.ttf", "Key DOWN : Go DOWN",
        (sfVector2f){869, 450}, (sfVector2f){0.8, 0.8});
    element[3] = create_text("assets/font.ttf", "Key LEFT : Go LEFT",
        (sfVector2f){869, 500}, (sfVector2f){0.8, 0.8});
    element[4] = create_text("assets/font.ttf", "Key RIGHT : Go RIGHT",
        (sfVector2f){869, 550}, (sfVector2f){0.8, 0.8});
    element[5] = create_text("assets/font.ttf", "Key D : Sword attack",
        (sfVector2f){869, 600}, (sfVector2f){0.8, 0.8});
    element[6] = create_text("assets/font.ttf", "Key Q : Bow attack",
        (sfVector2f){869, 650}, (sfVector2f){0.8, 0.8});
    element[7] = create_text("assets/font.ttf", "Key E : Interaction",
        (sfVector2f){869, 700}, (sfVector2f){0.8, 0.8});
    element[8] = create_text("assets/font.ttf", "SAVE EVENT",
        (sfVector2f){1450, 453}, (sfVector2f){0.6, 0.6});
    element[9] = create_text("assets/font.ttf", "NPC EVENT",
        (sfVector2f){1450, 553}, (sfVector2f){0.6, 0.6});
}