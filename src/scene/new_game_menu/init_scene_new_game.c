/*
** EPITECH PROJECT, 2019
** ini
** File description:
** i
*/

#include "my_rpg.h"

void init_sound_game(sound_t *element)
{
    element[0] = create_sound("assets/button.ogg", effect_vol, sfFalse);
    element[0].type = EFFECT;
    element[1] = create_sound("assets/button_pressed.ogg",
        effect_vol, sfFalse);
    element[1].type =  EFFECT;
}

void init_button_game(button_t *element, sound_t *sound)
{
    element[0] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){370, 714}, (sfVector2f){250, 320});
    element[0].button_role = NEW_PARTY;
    element[0].callback = &new_game;
    element[0].sound = sound[0].music;

    element[1] = create_button("assets/button_UP.png", "assets/button_P.png",
        (sfVector2f){1100, 714}, (sfVector2f){250, 320});
    element[1].button_role = LOAD_PARTY;
    element[1].callback = &load_game;
    element[1].sound = sound[0].music;
}

void init_sprite_game(sprite_t *element)
{
    element[0] = create_sprite("assets/map.png",
        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    sfSprite_scale(element[0].sprite, (sfVector2f){4.3, 4.3});
    sfSprite_setTextureRect(element[0].sprite, spawn_pos);
    element[1] = create_sprite("assets/end.png",
        (sfVector2f){1400, 900}, (sfVector2f){0, 0});
}

void init_text_game(text_t *element)
{
    element[0] = create_text("assets/font.ttf", "Press escape to leave",
        (sfVector2f){1500, 1030}, (sfVector2f){0.5, 0.5});
    element[1] = create_text("assets/font.ttf", "NORMAL LINK",
        (sfVector2f){418, 746}, (sfVector2f){0.8, 0.8});
    element[2] = create_text("assets/font.ttf", "DARK LINK",
        (sfVector2f){1140, 746}, (sfVector2f){0.8, 0.8});
}
