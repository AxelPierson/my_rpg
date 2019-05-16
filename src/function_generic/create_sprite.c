/*
** EPITECH PROJECT, 2019
** create_sprite
** File description:
** create_sprite
*/

#include "my_rpg.h"

sprite_t create_sprite(char *path, sfVector2f position, sfVector2f size)
{
    sprite_t element;

    element.tex = sfTexture_createFromFile(path, NULL);
    element.sprite = sfSprite_create();
    element.size = size;
    sfSprite_setTexture(element.sprite, element.tex, sfTrue);
    sfSprite_setPosition(element.sprite, position);
    return (element);
}