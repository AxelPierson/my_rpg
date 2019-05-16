/*
** EPITECH PROJECT, 2019
** text box
** File description:
** text_box
*/

#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include "lib.h"
#include "ocarina.h"

typedef struct text_box_s {
    int status;
    ocarina_t *time;
    int index;
    int len;
    int max_len;
    char *text;
    char save;
    sfText *line;
    sfFont *font;
    sfRectangleShape *box;
} text_box_t;

text_box_t *create_textbox(void);
void new_textbox(text_box_t *box, char *text);
void update_textbox(text_box_t *box, sfRenderWindow *win, int *evt);

#endif