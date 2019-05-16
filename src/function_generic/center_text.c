/*
** EPITECH PROJECT, 2019
** center text
** File description:
** center_text
*/

#include "lib.h"

void center_text(sfVector2f pos_zone, sfVector2f size_zone, sfText *text)
{
    int len = 0;
    int c_size = sfText_getCharacterSize(text);
    char const *str = sfText_getString(text);
    sfVector2f scale = sfText_getScale(text);
    sfVector2f text_pos;

    for (; str[len]; len++);
    text_pos.x = ((pos_zone.x + (size_zone.x / 2)) -
        (len * c_size * scale.x / 2));
    text_pos.y = ((pos_zone.y + (size_zone.y / 2) - (c_size) * scale.y / 2));
    sfText_setPosition(text, text_pos);
}