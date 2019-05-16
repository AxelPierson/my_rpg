/*
** EPITECH PROJECT, 2019
** music
** File description:
** music
*/

#include "music.h"
#include "globals.h"

sfMusic *create_music(char *file)
{
    sfMusic *new_music = sfMusic_createFromFile(file);

    sfMusic_setLoop(new_music, sfTrue);
    sfMusic_setVolume(new_music, music_vol);
    return (new_music);
}

sfMusic **create_music_tab(void)
{
    sfMusic **music_tab = malloc(sizeof(sfMusic *) * 3);

    music_tab[0] = create_music("assets/overworld.ogg");
    music_tab[1] = create_music("assets/village.ogg");
    music_tab[2] = create_music("assets/boss.ogg");
    return (music_tab);
}

music_t *init_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    music->snd = create_music_tab();
    music->actual = -1;
    return (music);
}

void play_music(music_t *music, int index)
{
    if (music->actual != index) {
        if (music->actual != -1)
            sfMusic_stop(music->snd[music->actual]);
        sfMusic_play(music->snd[index]);
        music->actual = index;
    }
}

void update_music(music_t *music, sfVector2f link)
{
    if (link.x > 966 && link.x < 2096 && link.y < 956)
        play_music(music, 1);
    else if (link.x > 3133)
        play_music(music, 2);
    else
        play_music(music, 0);
    if (sound_activated == false)
        sfMusic_setVolume(music->snd[music->actual], 0);
    else
        sfMusic_setVolume(music->snd[music->actual], music_vol);
}