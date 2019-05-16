/*
** EPITECH PROJECT, 2019
** create_text
** File description:
** create_text
*/

#include "text.h"

text_t create_text(char *path, char *str, sfVector2f position,
    sfVector2f scale)
{
    text_t element;

    element.text = sfText_create();
    element.font = sfFont_createFromFile(path);
    sfText_setFont(element.text, element.font);
    sfText_setString(element.text, str);
    sfText_setPosition(element.text, position);
    sfText_scale(element.text, scale);
    return (element);
}