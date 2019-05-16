/*
** EPITECH PROJECT, 2019
** init
** File description:
** init
*/

#include "my_rpg.h"

void init_sprite_main_menu(sprite_t *element)
{
    element[0] = create_sprite("assets/parallax.png",
        (sfVector2f){-6336, -1080}, (sfVector2f){0, 0});
        sfSprite_scale(element[0].sprite, (sfVector2f){4.3, 4.3});
}

void init_button_main_menu_2(button_t *element, sound_t *sound)
{
    element[3] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){250, 560}, (sfVector2f){380, 90});
    element[3].callback = &credit;
    element[3].button_role = CREDIT;
    element[3].sound = sound[1].music;
    element[4] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){250, 680}, (sfVector2f){380, 90});
    element[4].callback = &leave_game;
    element[4].button_role = QUIT;
    element[4].sound = sound[1].music;
    element[2] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){250, 440}, (sfVector2f){380, 90});
    element[2].button_role = SETTINGS;
    element[2].callback = &settings_in_menu;
    element[2].sound = sound[1].music;
}

void init_button_main_menu(button_t *element, sound_t *sound)
{
    element[0] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){250, 200}, (sfVector2f){380, 90});
    element[0].button_role = NEW_PARTY;
    element[0].callback = &new_game;
    element[0].sound = sound[1].music;

    element[1] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){250, 320}, (sfVector2f){380, 90});
    element[1].button_role = LOAD_PARTY;
    element[1].callback = &load_game;
    element[1].sound = sound[1].music;
    init_button_main_menu_2(element, sound);
}

void init_text_main_menu(text_t *e)
{
    e[0] = create_text("assets/font.ttf", "NEW GAME",
        (sfVector2f){320, 225}, (sfVector2f){0.8, 0.8});
    center_text((sfVector2f){250, 200}, (sfVector2f){380, 90}, e[0].text);
    e[1] = create_text("assets/font.ttf", "LOAD GAME",
    (sfVector2f){320, 350}, (sfVector2f){0.8, 0.8});
    center_text((sfVector2f){250, 320}, (sfVector2f){380, 90}, e[1].text);
    e[2] = create_text("assets/font.ttf", "SETTINGS",
        (sfVector2f){350, 470}, (sfVector2f){0.8, 0.8});
    center_text((sfVector2f){250, 440}, (sfVector2f){380, 90}, e[2].text);
    e[3] = create_text("assets/font.ttf", "CREDIT",
        (sfVector2f){320, 590}, (sfVector2f){0.8, 0.8});
    center_text((sfVector2f){250, 560}, (sfVector2f){380, 90}, e[3].text);
    e[4] = create_text("assets/font.ttf", "LEAVE GAME",
        (sfVector2f){300, 710}, (sfVector2f){0.8, 0.8});
    center_text((sfVector2f){250, 680}, (sfVector2f){380, 90}, e[4].text);
}

void init_sound_main_menu(sound_t *element)
{
    element[0] = create_sound("assets/menu.ogg", music_vol, sfTrue);
    element[0].type = MUSIC;
    element[1] = create_sound("assets/button.ogg", effect_vol, sfFalse);
    element[1].type = EFFECT;
    element[2] = create_sound("assets/button_pressed.ogg", effect_vol, sfFalse);
    element[2].type =  EFFECT;
}