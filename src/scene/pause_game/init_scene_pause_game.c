/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"

void init_sound_pause(sound_t *element)
{
    element[0] = create_sound("assets/button.ogg",
        effect_vol, sfFalse);
    element[0].type = EFFECT;
    element[1] = create_sound("assets/button_pressed.ogg",
        effect_vol, sfFalse);
    element[1].type = EFFECT;
}

void norme_button_cpg(button_t *element, sound_t *sound)
{
    element[0] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){300, 280}, (sfVector2f){380, 90});
    element[0].button_role = RESUME;
    element[0].callback = &resume;
    element[0].sound = sound[0].music;
    element[1] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){300, 430}, (sfVector2f){380, 90});
    element[1].button_role = HOW_TO_PLAY;
    element[1].callback = &how_to_play;
    element[1].sound = sound[0].music;
}

void init_button_pause(button_t *element, sound_t *sound)
{
    norme_button_cpg(element, sound);
    element[2] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){300, 580}, (sfVector2f){380, 90});
    element[2].button_role = SETTINGS_GAME;
    element[2].callback = &settings_pause;
    element[2].sound = sound[0].music;
    element[3] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){300, 720}, (sfVector2f){380, 90});
        element[3].button_role = BACK_TO_MENU;
    element[3].callback = &back_to_menu;
    element[3].sound = sound[0].music;
}

void init_rectangle_pause(rectangle_t *element)
{
    element[0] = create_rectangle((sfVector2f){1920, 1080},
        (sfVector2f){0, 0}, (sfColor){0, 0, 0, 50});
}

void init_text_pause(text_t *element)
{
    element[0] = create_text("assets/font.ttf", "RESUME",
        (sfVector2f){370, 315}, (sfVector2f){0.8, 0.8});
    element[1] = create_text("assets/font.ttf", "HOW TO PLAY",
        (sfVector2f){370, 465}, (sfVector2f){0.8, 0.8});
    element[2] = create_text("assets/font.ttf", "SETTINGS",
        (sfVector2f){400, 615}, (sfVector2f){0.8, 0.8});
    element[3] = create_text("assets/font.ttf", "MENU",
        (sfVector2f){400, 755}, (sfVector2f){0.8, 0.8});
}