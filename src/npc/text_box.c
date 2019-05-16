/*
** EPITECH PROJECT, 2019
** text box
** File description:
** text box
*/

#include "text_box.h"
#include "string.h"

void init_var_texbox(text_box_t *box)
{
    box->font = sfFont_createFromFile("assets/font.ttf");
    box->len = 0;
    box->max_len = 0;
    box->index = 0;
    box->save = 'h';
    box->status = 0;
    box->text = NULL;
    box->time = create_ocarina();
}

text_box_t *create_textbox(void)
{
    text_box_t *box = malloc(sizeof(text_box_t));

    init_var_texbox(box);
    box->line = sfText_create();
    sfText_setCharacterSize(box->line, 20);
    sfText_setPosition(box->line, (sfVector2f){75, 905});
    sfText_setColor(box->line, sfGreen);
    sfText_setFont(box->line, box->font);
    box->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(box->box, (sfColor){ 179, 86, 0, 200});
    sfRectangleShape_setPosition(box->box, (sfVector2f){70, 900});
    sfRectangleShape_setOutlineThickness(box->box, 6);
    sfRectangleShape_setOutlineColor(box->box, (sfColor){ 255, 215, 0, 250});
    sfRectangleShape_setSize(box->box, (sfVector2f){50, 27});
    return (box);
}

void new_textbox(text_box_t *box, char *text)
{
    box->text = text;
    box->status = 1;
    box->index = 0;
    box->len = 0;
    box->max_len = 0;
    box->save = box->text[1];
    box->text[1] = '\0';
    sfRectangleShape_setSize(box->box, (sfVector2f){40, 27});
}

void draw_textbox(text_box_t *box)
{
    sfVector2f size = sfRectangleShape_getSize(box->box);

    if (box->save != '\0') {
        box->index += 1;
        box->len += 1;
        box->text[box->index] = box->save;
        box->save = box->text[box->index + 1];
        box->text[box->index + 1] = '\0';
        if (box->text[box->index - 1] ==  '\n') {
            size.y += 22;
            box->len = 0;
        } else if (box->len > box->max_len) {
            box->max_len = box->len;
            size.x += 20.4;
        }
        sfText_setString(box->line, box->text);
        sfRectangleShape_setSize(box->box, size);
    }
}

void update_textbox(text_box_t *box, sfRenderWindow *win, int *evt)
{
    if (box->status == 1) {
        box->time->time = sfClock_getElapsedTime(box->time->clock).microseconds
            / 1000000.0;
        if (box->time->time > 0.02) {
            draw_textbox(box);
            sfClock_restart(box->time->clock);
        }
        sfRenderWindow_drawRectangleShape(win, box->box, NULL);
        sfRenderWindow_drawText(win, box->line, NULL);
        if (box->save == '\0') {
            if (*evt == 2)
                *evt = 0;
        }
    }
}