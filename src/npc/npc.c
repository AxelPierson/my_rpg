/*
** EPITECH PROJECT, 2019
** npc
** File description:
** npc
*/

#include "npc.h"
#include "text_box.h"

npc_t *create_npc(sfVector2f pos, sfTexture **texture, sfSprite **spr, int max)
{
    npc_t *npc = malloc(sizeof(npc_t));
    unsigned int rnd = randr(1, max);

    rnd = max == 0 ? 0 : rnd;
    npc->pos = pos;
    npc->state = 0;
    npc->speaking = 0;
    npc->texture = texture[rnd];
    npc->spr = spr[rnd];
    npc->size = sfTexture_getSize(npc->texture);
    npc->size = (sfVector2u){npc->size.x * 4, npc->size.y * 4};
    sfSprite_setScale(npc->spr, (sfVector2f){4, 4});
    return (npc);
}

void create_rnd_dialog(people_t *pop)
{
    size_t n = 0;
    FILE *fd = fopen("assets/rnd_dialog", "r");
    char *buf = NULL;

    pop->rnd_dialog = malloc(sizeof(char *) * pop->nb_rnd);
    for (int i = 0; getline(&buf, &n, fd) != -1 &&
    i < pop->nb_rnd; i++) {
        pop->rnd_dialog[i] = strcopy(buf);
        n = 0;
        for (int j = 0; pop->rnd_dialog[i][j] != '\n' &&
        pop->rnd_dialog[i][j] != '\0'; j++)
            pop->rnd_dialog[i][j] = pop->rnd_dialog[i][j] == '~' ? '\n' :
                pop->rnd_dialog[i][j];
        free(buf);
    }
    fclose(fd);
}

void create_dialog(people_t *pop)
{
    size_t n = 0;
    FILE *fd = fopen("assets/quest_dialog", "r");
    char *buf = NULL;

    pop->quest_dialog = malloc(sizeof(char *) * pop->nb_quest);
    for (int i = 0; getline(&buf, &n, fd) != -1
    && i < pop->nb_quest; i++) {
        pop->quest_dialog[i] = strcopy(buf);
        n = 0;
        for (int j = 0; pop->quest_dialog[i][j] != '\n' &&
        pop->quest_dialog[i][j] != '\0'; j++)
            pop->quest_dialog[i][j] = pop->quest_dialog[i][j] == '~' ? '\n':
                pop->quest_dialog[i][j];
        free(buf);
    }
    fclose(fd);
    create_rnd_dialog(pop);
}

void create_quest(people_t *pop, game_t * game)
{
    pop->npc[0] = create_npc((sfVector2f){2675, 7377},
        pop->texture, pop->spr, pop->nb_spr);
    pop->npc[0]->state = 1;
    pop->npc[1] = create_npc((sfVector2f){6360, 3223},
        pop->texture, pop->spr, 0);
    pop->npc[1]->state = 2;
    pop->npc[2] = create_npc((sfVector2f){8625, 2605},
        pop->texture, pop->spr, pop->nb_spr);
    pop->npc[2]->state = 3;
    pop->npc[3] = create_npc((sfVector2f){6666, 5550},
        pop->texture, pop->spr, pop->nb_spr);
    pop->npc[3]->state = 5;
    pop->npc[4] = create_npc((sfVector2f){13760, 4300},
        pop->texture, pop->spr, pop->nb_spr);
    pop->npc[4]->state = 8;
    init_quest(pop, game);
}

people_t *create_people(game_t *game)
{
    people_t *pop = malloc(sizeof(people_t));

    pop->nb_spr = 34;
    pop->texture = fill_texture("assets/npc_sprite", pop->nb_spr);
    pop->spr = fill_sprites(pop->nb_spr, pop->texture);
    pop->col = (npc_col_t){1, 1, 1, 1};
    pop->pop = 30;
    pop->nb_rnd = 33;
    pop->nb_quest = 9;
    create_dialog(pop);
    pop->npc = malloc(sizeof(npc_t *) * pop->pop);
    create_quest(pop, game);
    create_rng_npc(pop);
    return (pop);
}