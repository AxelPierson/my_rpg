/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my_rpg.h"
#include "link.h"
#include "fade.h"
#include "text_box.h"
#include "npc.h"

int is_touch_pressed(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
    sfKeyboard_isKeyPressed(sfKeyDown) ||
    sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyRight))
        return true;
    return false;
}

void norme_view(game_t *game, scene_t *game_scene, link_t *
    link, float delta_time)
{
    float disp = (link->speed / delta_time);

    if (sfKeyboard_isKeyPressed(sfKeyUp) && check_collision(game_scene, link,
    0, disp) == 1 && game->pop->col.up)
        link->ground.top -= round(disp);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && check_collision(game_scene, link,
    1, disp) == 1 && game->pop->col.down)
        link->ground.top += round(disp);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && check_collision(game_scene, link,
    2, disp) == 1 && game->pop->col.left)
        link->ground.left -= round(disp);
    if (sfKeyboard_isKeyPressed(sfKeyRight) && check_collision(game_scene, link,
    3, disp) == 1 && game->pop->col.right)
        link->ground.left += round(disp);
    sfSprite_setTextureRect(game_scene->sprite[0].sprite, link->ground);
}

void update_view(game_t *game, scene_t *game_scene, link_t *
    link, float delta_time)
{
    if (link->previous_anim >= 4)
        return;
    if (is_touch_pressed() == false)
        return;
    if (link->previous_anim >= 4)
        return;
    norme_view(game, game_scene, link, delta_time);
}

void draw_link(link_t *link, window_t *win, void *extra)
{
    (void)extra;
    link->ocarina->time = sfClock_getElapsedTime(
        link->ocarina->clock).microseconds / 1000000.0;
    sfRenderWindow_drawSprite(win->window, link->spr, NULL);
    if (link->arrow->state == 1)
        sfRenderWindow_drawSprite(win->window, link->arrow->spr, NULL);
}

int new_game(game_t *game, window_t *window, void *extra)
{
    (void)extra;
    int looping = char_selec(game, window, NULL);

    if (looping == true)
        play_game(game, window);
    return (true);
}