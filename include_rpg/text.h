/*
** EPITECH PROJECT, 2019
** text
** File description:
** text
*/

#ifndef TEXT_H_
#define TEXT_H_

#include "my_rpg.h"

typedef struct text_s {
    sfText *text;
    sfFont *font;
} text_t;

void center_text(sfVector2f pos_zone, sfVector2f size_zone, sfText *text);

#endif /* !TEXT_H_ */