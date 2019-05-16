/*
** EPITECH PROJECT, 2019
** sound
** File description:
** sound
*/

#include "lib.h"
#include "link.h"
#include "game.h"
#include "globals.h"

sfSound *create_snd(char *file)
{
    sfSound *snd = sfSound_create();
    sfSoundBuffer *buf = sfSoundBuffer_createFromFile(file);

    sfSound_setBuffer(snd, buf);
    sfSound_setVolume(snd, effect_vol);
    return (snd);
}

sfSound **create_sound_tab(void)
{
    sfSound **snd = malloc(sizeof(sfSound *) * 6);

    snd[0] = create_snd("assets/link_sword.ogg");
    snd[1] = create_snd("assets/link_attack.ogg");
    snd[2] = create_snd("assets/link_attack1.ogg");
    snd[3] = create_snd("assets/link_attack2.ogg");
    snd[4] = create_snd("assets/link_bow.ogg");
    snd[5] = create_snd("assets/round.ogg");
    return (snd);
}

void destroy_sound_tab(game_t *game)
{
    int i = 6;

    if (game->link == NULL)
        i = 0;
    for (int j = 0; j < i; j++) {
        sfSound_destroy(game->link->snd[j]);
    }
    for (int l = 0; l < 3; l++)
        sfMusic_destroy(game->music->snd[l]);
}
