/*
** EPITECH PROJECT, 2019
** fade
** File description:
** fade_screen
*/

#include "fade.h"

fade_t *create_fade(void)
{
    fade_t *fade = malloc(sizeof(fade_t));

    fade->state = 3;
    fade->index = 1;
    fade->ocarina = create_ocarina();
    fade->circle = sfCircleShape_create();
    sfCircleShape_setOutlineThickness(fade->circle, 1500);
    sfCircleShape_setFillColor(fade->circle, (sfColor){0, 0, 0, 0});
    sfCircleShape_setOutlineColor(fade->circle, sfBlack);
    sfCircleShape_setPointCount(fade->circle, 6);
    return (fade);
}

void close_fade(fade_t *fade, window_t *window)
{
    if (fade->state == 1) {
        if (fade->index <= 0) {
            fade->index = 1;
            fade->state = 2;
            sfRenderWindow_clear(window->window, sfBlack);
            return;
        }
        fade->ocarina->time = sfClock_getElapsedTime
            (fade->ocarina->clock).microseconds / 1000000.0;
        if (fade->ocarina->time > 0.01) {
            sfCircleShape_setRadius(fade->circle, fade->index);
            sfCircleShape_setPosition(fade->circle,
                (sfVector2f){960 - fade->index, 540 - fade->index});
            fade->index -= 15;
            sfClock_restart(fade->ocarina->clock);
        }
        sfRenderWindow_drawCircleShape(window->window, fade->circle, NULL);
    }
}

void open_fade(fade_t *fade, window_t *window)
{
    if (fade->state == 3) {
        if (fade->index >= 1080) {
            fade->index = 1080;
            fade->state = 0;
            return;
        }
        fade->ocarina->time = sfClock_getElapsedTime
            (fade->ocarina->clock).microseconds / 1000000.0;
        if (fade->ocarina->time > 0.01) {
            sfCircleShape_setRadius(fade->circle, fade->index);
            sfCircleShape_setPosition(fade->circle,
                (sfVector2f){960 - fade->index, 540 - fade->index});
            fade->index += 15;
            sfClock_restart(fade->ocarina->clock);
        }
        sfRenderWindow_drawCircleShape(window->window, fade->circle, NULL);
    }
}

void use_fade(fade_t *fade, window_t *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyX)) {
        fade->state = 1;
        fade->index = 1080;
    }
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        fade->state = 3;
    }
    if (fade->state == 2)
        sfRenderWindow_clear(window->window, sfBlack);
    open_fade(fade, window);
    close_fade(fade, window);
}