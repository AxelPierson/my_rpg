/*
** EPITECH PROJECT, 2019
** npc
** File description:
** npc
*/

#ifndef NPC_H
#define NPC_H

#include "lib.h"
#include "link.h"
#include "game.h"

typedef struct npc_col_s {
    int up;
    int down;
    int right;
    int left;
} npc_col_t;

typedef struct npc_s {
    int speaking;
    int state;
    sfTexture *texture;
    sfSprite *spr;
    sfVector2f pos;
    sfVector2u size;
} npc_t;

typedef struct people_s {
    int pop;
    int nb_spr;
    npc_t **npc;
    char **rnd_dialog;
    sfTexture **texture;
    sfSprite **spr;
    int nb_rnd;
    char **quest_dialog;
    int nb_quest;
    npc_col_t col;
} people_t;

sfTexture **fill_texture(char *file, int size);
sfSprite **fill_sprites(int size, sfTexture **texture);

unsigned int randr(unsigned int min, unsigned int max);
void draw_icon(game_t *game, window_t *window, int index);
npc_t *create_npc(sfVector2f pos, sfTexture **texture, sfSprite **spr, int max);

people_t *create_people(game_t *game);
void update_npc(game_t *game, people_t *pop, sfRenderWindow *win);

void random_npc(game_t *game, people_t *pop, sfRenderWindow *win, npc_t *npc);
void quest_npc(game_t *game, people_t *pop, sfRenderWindow *win, npc_t *npc);

void quest(game_t *game, npc_t *npc);
void init_quest(people_t *pop, game_t *game);
void create_rng_npc(people_t *pop);

#endif