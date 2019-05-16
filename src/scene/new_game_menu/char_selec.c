/*
** EPITECH PROJECT, 2019
** char
** File description:
** char
*/

#include "my_rpg.h"

int get_char(int *button_selected, game_t *game)
{
    switch (*button_selected) {
        case 0: game->link = create_link((sfColor){255, 255, 255, 255});
            game->link->color_selected = 0;
                break;
        case 1: game->link = create_link((sfColor){75, 75, 75, 255});
            game->link->color_selected = 1;
                break;
        default:
            break;
    }
    return (false);
}

int char_selec_event(game_t *game, window_t *window, int *button_selected)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtKeyReleased) {
            if (window->event.key.code == sfKeyEscape)
                return (QUIT);
            if (window->event.key.code == sfKeyReturn)
                return (get_char(button_selected, game));
            update_button_selected(window->event, button_selected, (int[3]){
                    NORMAL_LINK, DARK_LINK, 2}, &game->scene[S_MAIN_MENU]);
        }
    }
    return (true);
}

int char_selec(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int button_selected = NORMAL_LINK;
    int looping = true;

    while (looping == true) {
        looping = char_selec_event(game, window, &button_selected);
        music_update(game->scene[S_GAME].sound, 2);
        sfRenderWindow_clear(window->window, sfBlack);
        draw_parallax_menu(window, &game->scene[S_MAIN_MENU]);
        draw_x_button(2, game->scene[S_GAME].button, window, button_selected);
        draw_x_text(3, game->scene[S_GAME].text, window);
        sfRenderWindow_display(window->window);
    }
    if (looping == QUIT)
        return (QUIT);
    reset_spawn_value(game, (sfIntRect){575, 1611, 1920, 1080});
    write_save(game);
    return (true);
}