/*
** EPITECH PROJECT, 2019
** talk npc
** File description:
** talk_npc
*/

#include "npc.h"
#include "text_box.h"

void collide_npc(npc_t *npc, people_t *pop, link_t *link)
{
    if ((link->pos.x + 7) * 4.3 + (link->speed * DT) >= npc->pos.x &&
    (link->pos.x)* 4.3 + (link->speed * DT)
    <= npc->pos.x + npc->size.x && (link->pos.y) * 4.3 >= npc->pos.y &&
    link->pos.y * 4.3 <= npc->pos.y + npc->size.y)
        pop->col.right = 0;
    if ((link->pos.x) * 4.3 - (link->speed * DT) >= npc->pos.x &&
    (link->pos.x - 7)* 4.3 - (link->speed * DT)
    <= npc->pos.x + npc->size.x && (link->pos.y) * 4.3 >= npc->pos.y &&
    link->pos.y * 4.3 <= npc->pos.y + npc->size.y)
        pop->col.left = 0;
    if ((link->pos.x) * 4.3 >= npc->pos.x &&
    link->pos.x * 4.3 <= npc->pos.x + npc->size.x &&
    (link->pos.y + 12) * 4.3 + (link->speed * DT) >= npc->pos.y &&
    link->pos.y * 4.3 + (link->speed * DT) <= npc->pos.y + npc->size.y)
        pop->col.down = 0;
    if ((link->pos.x) * 4.3 >= npc->pos.x && link->pos.x * 4.3 <= npc->pos.x +
    npc->size.x && link->pos.y * 4.3 - (link->speed * DT) >= npc->pos.y
    && (link->pos.y - 12) * 4.3 - (link->speed * DT)
    <= npc->pos.y + npc->size.y)
        pop->col.up = 0;
}

void npc_textbox(npc_t *npc, char *line, game_t *game, sfRenderWindow *win)
{
    if (game->link->pos.x * 4.3 >= npc->pos.x &&
        game->link->pos.x * 4.3 <= npc->pos.x + npc->size.x &&
        game->link->pos.y * 4.3 >= npc->pos.y &&
        game->link->pos.y * 4.3 <= npc->pos.y + npc->size.y + 100) {
        if (game->link->event == 2 && game->box->status == 0) {
            game->link->event = 0;
            new_textbox(game->box, line);
            npc->speaking = 1;
            quest(game, npc);
        } else if (game->link->event != 2 && game->box->status == 0)
            sfRenderWindow_drawSprite(win, game->ui.icon[I_CHAT].sprite, NULL);
    }
}

void random_npc(game_t *game, people_t *pop, sfRenderWindow *win, npc_t *npc)
{
    unsigned int rnd = randr(0, pop->nb_rnd);

    if (npc->pos.x >= game->link->ground.left * 4.3 - npc->size.x &&
        npc->pos.x <= game->link->ground.left * 4.3 + 1920 &&
        npc->pos.y >= game->link->ground.top * 4.3 - npc->size.y &&
        npc->pos.y <= game->link->ground.top * 4.3 + 1080) {
        sfSprite_setPosition(npc->spr, (sfVector2f){npc->pos.x - game->link
            ->ground.left * 4.3, npc->pos.y - game->link->ground.top * 4.3});
        sfRenderWindow_drawSprite(win, npc->spr, NULL);
        collide_npc(npc, pop, game->link);
        npc_textbox(npc, pop->rnd_dialog[rnd], game, win);
    } else if (game->box->save == '\0' && npc->speaking) {
        game->box->status = 0;
        npc->speaking = 0;
    }
}

void quest_npc(game_t *game, people_t *pop, sfRenderWindow *win, npc_t *npc)
{
    if (npc->pos.x >= game->link->ground.left * 4.3 - npc->size.x &&
        npc->pos.x <= game->link->ground.left * 4.3 + 1920 &&
        npc->pos.y >= game->link->ground.top * 4.3 - npc->size.y &&
        npc->pos.y <= game->link->ground.top * 4.3 + 1080) {
        sfSprite_setPosition(npc->spr, (sfVector2f){npc->pos.x - game->link
            ->ground.left * 4.3, npc->pos.y - game->link->ground.top * 4.3});
        sfRenderWindow_drawSprite(win, npc->spr, NULL);
        collide_npc(npc, pop, game->link);
        npc_textbox(npc, pop->quest_dialog[npc->state], game, win);
    }  else if (game->box->save == '\0' && npc->speaking) {
        game->box->status = 0;
        npc->speaking = 0;
    }
}

void update_npc(game_t *game, people_t *pop, sfRenderWindow *win)
{
    pop->col = (npc_col_t){1, 1, 1, 1};
    for (int i = 0; i < pop->pop; i++) {
        if (pop->npc[i]->state == 0)
            random_npc(game, pop, win, pop->npc[i]);
        else {
            quest_npc(game, pop, win, pop->npc[i]);
        }
    }
    if (game->link->event == 2 && game->box->save == '\0') {
        game->link->event = 0;
        game->box->status = 0;
    } else
        game->link->event = 0;
}