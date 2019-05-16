/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my_rpg.h"
#include "game.h"
#include "globals.h"
#include "fade.h"
#include "zone.h"
#include "npc.h"

void free_map_colli(void)
{
    for (int i = 0; i < 135; i++) {
        free(map_test[i]);
    }
    free(map_test);
}

void free_game(game_t *game)
{
    free_music(&game->scene[S_MAIN_MENU], 3);
    free_music(&game->scene[S_SETTINGS_MENU], 2);
    free_music(&game->scene[S_PAUSE_GAME], 2);
    free_music(&game->scene[S_SETTINGS_PAUSE], 2);
    free_music(&game->scene[S_GAME], 2);
    destroy_sound_tab(game);
    free_map_colli();
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    srand(time(0));
    window_t *window = NULL;
    game_t *game = NULL;
    srand(time(NULL));

    if (env[0] == NULL)
        return (84);
    window = init_window();
    if (init_globals() == 84)
        return (84);
    game = init_game();
    while (sfRenderWindow_isOpen(window->window)) {
        if (loop_main_menu(window, game) == QUIT)
            break;
    }
    free_game(game);
    sfRenderWindow_destroy(window->window);
    return (0);
}