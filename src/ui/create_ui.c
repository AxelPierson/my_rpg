/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"
#include "game.h"
#include "globals.h"

checkpoint_t create_checkpoint(sfVector2f pos)
{
    checkpoint_t element;

    element.size = (sfVector2f){68, 136};
    element.position = pos;
    element.shape = sfRectangleShape_create();
    sfRectangleShape_setSize(element.shape, (sfVector2f){68, 136});
    sfRectangleShape_setFillColor(element.shape, sfBlue);
    sfRectangleShape_setPosition(element.shape, pos);
    return (element);
}

heart_t create_heart(char *path, sfVector2f position)
{
    heart_t element;

    element.tex = sfTexture_createFromFile(path, NULL);
    element.spr = sfSprite_create();
    element.status = H_FULL;
    sfSprite_setTexture(element.spr, element.tex, sfTrue);
    sfSprite_setPosition(element.spr, position);
    return (element);
}

item_t create_item(char *path, sfVector2f position)
{
    item_t element;

    element.tex = sfTexture_createFromFile(path, NULL);
    element.spr = sfSprite_create();
    element.status = false;
    sfSprite_setTexture(element.spr, element.tex, sfTrue);
    sfSprite_setPosition(element.spr, position);
    return (element);
}

icon_t create_icon(char *path, sfVector2f position, sfVector2f size)
{
    icon_t element;

    element.tex = sfTexture_createFromFile(path, NULL);
    element.sprite = sfSprite_create();
    element.size = size;
    element.status = false;
    sfSprite_setTexture(element.sprite, element.tex, sfTrue);
    sfSprite_setPosition(element.sprite, position);
    return (element);
}

counter_t create_counter(int n, sfVector2f pos, sfVector2f scale)
{
    counter_t counter;

    counter.n = n;
    counter.status = false;
    counter.drawable = false;
    counter.text = sfText_create();
    counter.font = sfFont_createFromFile("assets/font.ttf");
    sfText_setFont(counter.text, counter.font);
    sfText_setString(counter.text, int_char(n));
    sfText_setPosition(counter.text, pos);
    sfText_scale(counter.text, scale);
    return (counter);
}