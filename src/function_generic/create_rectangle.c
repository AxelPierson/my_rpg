/*
** EPITECH PROJECT, 2019
** create
** File description:
** creat
*/

#include "rectangle.h"
#include "lib.h"

rectangle_t create_rectangle(sfVector2f size,
    sfVector2f position, sfColor color)
{
    rectangle_t element;

    element.shape = sfRectangleShape_create();
    sfRectangleShape_setSize(element.shape, size);
    sfRectangleShape_setFillColor(element.shape, color);
    sfRectangleShape_setPosition(element.shape, position);
    return (element);
}