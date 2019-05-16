/*
** EPITECH PROJECT, 2019
** i
** File description:
** i
*/

#include "my_rpg.h"
#include "game.h"
#include "globals.h"

void init_heart(heart_t *heart, game_t *game)
{
    sfIntRect rect = {0, 0, 43, 43};

    game->ui.life = create_sprite("assets/life.png",
        (sfVector2f){355, 5}, (sfVector2f){0, 0});
    heart[0] = create_heart("assets/heart.png", (sfVector2f){375, 45});
    sfSprite_setTextureRect(heart[0].spr, rect);
    heart[1] = create_heart("assets/heart.png", (sfVector2f){434, 45});
    sfSprite_setTextureRect(heart[1].spr, rect);
    heart[2] = create_heart("assets/heart.png", (sfVector2f){492, 45});
    sfSprite_setTextureRect(heart[2].spr, rect);
}

void init_item(game_t *game, item_t *item)
{
    game->ui.arrow = create_counter(20,
        (sfVector2f){1358, 31}, (sfVector2f){0.4, 0.4});
    item[0] = create_item("assets/sword.png", (sfVector2f){1417, 20});
    item[1] = create_item("assets/logo.png", (sfVector2f){1302, 20});
    item[2] = create_item("assets/logo.png", (sfVector2f){1187, 20});
}

void init_icon(icon_t *icon)
{
    icon[I_HEAD] = create_icon("assets/i_head.png",
        set_icon((sfVector2f){52, 60}), (sfVector2f){52, 60});
    icon[I_CHAT] = create_icon("assets/i_chat.png",
        set_icon((sfVector2f){52, 54}), (sfVector2f){52, 54});
}

void init_ui(game_t *game)
{
    game->ui.regen = sfClock_create();
    game->ui.heart = malloc(sizeof(heart_t) * 3);
    game->ui.item = malloc(sizeof(item_t) * 3);
    game->ui.texture = malloc(sizeof(sfTexture *) * 4);
    game->ui.icon = malloc(sizeof(icon_t) * 2);
    init_tex(game->ui.texture);
    init_heart(game->ui.heart, game);
    init_item(game, game->ui.item);
    init_icon(game->ui.icon);
}

void init_checkpoint(game_t *game)
{
    game->sign[0] = create_checkpoint((sfVector2f){3234, 7706});
    game->sign[1] = create_checkpoint((sfVector2f){3574, 4610});
    game->sign[2] = create_checkpoint((sfVector2f){7023, 5300});
    game->sign[3] = create_checkpoint((sfVector2f){8744, 2760});
    game->sign[4] = create_checkpoint((sfVector2f){4816, 2680});
    game->sign[5] = create_checkpoint((sfVector2f){13279, 4126});
}