/*
** EPITECH PROJECT, 2019
** random
** File description:
** random
*/

#include "lib.h"

unsigned int randr(unsigned int min, unsigned int max)
{
    unsigned int r = max - min;

    if (r == 0)
        return (0);
    r = rand() % (max - min) + min;
    return (r);
}