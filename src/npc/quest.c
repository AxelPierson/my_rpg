/*
** EPITECH PROJECT, 2019
** quest
** File description:
** quest
*/

#include "npc.h"

void quest(game_t *game, npc_t *npc)
{
    if (npc->state == 5) {
        game->pop->npc[2]->state = 4;
        npc->state = 6;
        game->ui.arrow.drawable = true;
        get_bow(game);
    }
}

void init_quest(people_t *pop, game_t *game)
{
    if (game->ui.arrow.drawable) {
        get_bow(game);
        pop->npc[2]->state = 4;
        pop->npc[3]->state = 6;
    }
}

void create_rng_npc(people_t *pop)
{
    sfVector2f *pos = (sfVector2f[25]){{5490, 2205}, {6123, 2610}, {6695, 761}
    , {6179, 1075}, {5104, 2992}, {4536, 731}, {5340, 830}, {5220, 2524},
    {4936, 1419}, {5727, 1122}, {6450, 774}, {7404, 705}, {7034, 1242},
    {7740, 1161}, {8118, 1247}, {8454, 1771}, {6858, 2309}, {7310, 2055},
    {8385, 2330}, {2000, 3083}, {7725, 3827}, {7009, 3818}, {6450, 3934},
    {6020, 3784}, {5642, 3600}};
    int j = 0;

    for (int i = 5; i < pop->pop; i++) {
        pop->npc[i] = create_npc(pos[j], pop->texture, pop->spr, pop->nb_spr);
        j++;
    }
}