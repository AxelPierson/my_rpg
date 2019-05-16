/*
** EPITECH PROJECT, 2019
** window
** File description:
** window
*/

#include "my_rpg.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "RPG",
        sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(window, false);
    return (window);
}

window_t *init_window(void)
{
    window_t *element = malloc(sizeof(window_t));

    element->window = create_window();
    sfRenderWindow_setFramerateLimit(element->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(element->window, sfFalse);
    return (element);
}