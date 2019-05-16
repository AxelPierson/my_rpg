/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"

void norme_ibsp(button_t *e, sound_t *sound)
{
    e[0] = create_button("assets/button_UP_S.png", "assets/button_P_S.png",
        (sfVector2f){1350, 320}, (sfVector2f){90, 98});
    e[0].button_role = VOL_EFFECT_D;
    e[0].sound = sound[0].music;
    e[0].callback = &effect_vol_d;
    e[1] = create_button("assets/button_UP_S.png", "assets/button_P_S.png",
        (sfVector2f){1450, 320}, (sfVector2f){90, 98});
    e[1].button_role = VOL_EFFECT_U;
    e[1].sound = sound[0].music;
    e[1].callback = &effect_vol_u;
    e[2] = create_button("assets/button_UP_S.png", "assets/button_P_S.png",
        (sfVector2f){1350, 510}, (sfVector2f){90, 98});
    e[2].button_role = VOL_MUSIC_D;
    e[2].sound = sound[0].music;
    e[2].callback = &effect_music_d;
}

void init_button_settings_pause(button_t *e, sound_t *sound)
{
    norme_ibsp(e, sound);
    e[3] = create_button("assets/button_UP_S.png", "assets/button_P_S.png",
        (sfVector2f){1450, 510}, (sfVector2f){90, 98});
    e[3].button_role = VOL_MUSIC_U;
    e[3].sound = sound[0].music;
    e[3].callback = &effect_music_u;
    e[4] = create_button("assets/button_UP_S.png", "assets/button_P_S.png",
        (sfVector2f){1350, 700}, (sfVector2f){90, 98});
    e[4].button_role = VOL_ON;
    e[4].sound = sound[0].music;
    e[4].callback = &vol_on;
    e[5] = create_button("assets/button_UP_S.png", "assets/button_P_S.png",
        (sfVector2f){1450, 700}, (sfVector2f){90, 98});
    e[5].button_role = VOL_OFF;
    e[5].sound = sound[0].music;
    e[5].callback = &vol_off;
}

void init_sound_settings_pause(sound_t *element)
{
    element[0] = create_sound("assets/button.ogg",
        effect_vol, sfFalse);
    element[0].type = EFFECT;
    element[1] = create_sound("assets/button_pressed.ogg",
        effect_vol, sfFalse);
    element[1].type = EFFECT;
}

void norme_tsp(text_t *element)
{
    element[0] = create_text("assets/font.ttf", "Press escape to leave",
        (sfVector2f){1500, 1030}, (sfVector2f){0.5, 0.5});
    element[1] = create_text("assets/font.ttf", "Effect",
        (sfVector2f){1090, 340}, (sfVector2f){1, 1});
    element[2] = create_text("assets/font.ttf", "Music",
        (sfVector2f){1090, 530}, (sfVector2f){1, 1});
}

void init_text_settings_pause(text_t *element)
{
    norme_tsp(element);
    element[3] = create_text("assets/font.ttf", "Sound",
        (sfVector2f){1110, 725}, (sfVector2f){1, 1});
    element[4] = create_text("assets/font.ttf", "ON",
        (sfVector2f){1375, 735}, (sfVector2f){0.7, 0.7});
    element[5] = create_text("assets/font.ttf", "OFF",
        (sfVector2f){1468, 735}, (sfVector2f){0.7, 0.7});
    element[6] = create_text("assets/font.ttf", "-",
        (sfVector2f){1375, 355}, (sfVector2f){0.7, 0.7});
    element[7] = create_text("assets/font.ttf", "+",
        (sfVector2f){1468, 355}, (sfVector2f){0.7, 0.7});
    element[8] = create_text("assets/font.ttf", "-",
        (sfVector2f){1375, 545}, (sfVector2f){0.7, 0.7});
    element[9] = create_text("assets/font.ttf", "+",
        (sfVector2f){1468, 545}, (sfVector2f){0.7, 0.7});
}