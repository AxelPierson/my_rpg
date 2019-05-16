/*
** EPITECH PROJECT, 2019
** rect
** File description:
** rect
*/

#include "lib.h"

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect element;

    element.top = top;
    element.left = left;
    element.width = width;
    element.height = height;
    return (element);
}