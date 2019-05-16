/*
** EPITECH PROJECT, 2019
** create
** File description:
** create
*/

#include "my_rpg.h"

button_t create_button(char *b_unpressed, char *b_pressed,
    sfVector2f position, sfVector2f size)
{
    button_t element;

    element.tex0 = sfTexture_createFromFile(b_unpressed, NULL);
    element.sprite0 = sfSprite_create();
    sfSprite_setTexture(element.sprite0, element.tex0, sfTrue);
    element.tex1 = sfTexture_createFromFile(b_pressed, NULL);
    element.sprite1 = sfSprite_create();
    sfSprite_setTexture(element.sprite1, element.tex1, sfTrue);
    sfSprite_setPosition(element.sprite0, position);
    sfSprite_setPosition(element.sprite1, position);
    element.size = size;
    return (element);
}